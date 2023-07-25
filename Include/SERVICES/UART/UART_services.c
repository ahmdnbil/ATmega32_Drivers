

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "./UART_services.h"

void FUNC_TX();
void FUNC_RX();
static u8* Asynch_Sent_Str    =NULLPTR;
static u8* Asynch_receive_Str =NULLPTR;



/**********************************************************************************/
                            /*send string techniques*/

//Send String synch blocking
void UART_voidSendStringSynchBlocking(u8 *A_u8Word)
{
    u8 local_u8Counter=0;
    while(A_u8Word[local_u8Counter] != '\0')
    {
        UART_voidSendByteSynchBlocking(A_u8Word[local_u8Counter]);
        local_u8Counter++;
    }
}

//send string asynch non-blocking
void UART_voidSendStingAsynch(u8 *ptr)
{
    UART_voidSetCallTXC(FUNC_TX);
    UART_voidTXCompleteInterruptEnable();
    UART_voidSendByteAsynch(ptr[0]);
    Asynch_Sent_Str=ptr;
}

//send this function to ISR
void FUNC_TX()
{
    static u8 i=1;
    if(Asynch_Sent_Str[i]!='\0')
    {
        UART_voidSendByteAsynch(Asynch_Sent_Str[i]);
        i++;
    }
    else i=1;
}
/**********************************************************************************/



/**********************************************************************************/
                            /*receive string techniques*/
void UART_voidReceiveString(u8 *ptr)
{
    u8 i=0;
    ptr[i] = UART_u8ReadByteSynchBlocking();
    /*
        0x0d is hex code for enter in proteus
        in docklight you send two numbers when you push enter 10 13 for example
    */
    while(ptr[i]!=0x0d)
    {
        i++;
        ptr[i] = UART_u8ReadByteSynchBlocking();
    }
    ptr[i]='\0';
}

void UART_voidReceiveStringAsynch(u8 *str)
{
    UART_voidSetCallRXC(FUNC_RX);
    UART_voidRXCompleteInterruptEnable();
    Asynch_receive_Str=str;
}

void FUNC_RX()
{
    static u8 i=0;
    Asynch_receive_Str[i] = UART_u8ReadByteAsynch();
    i++;
}

/**********************************************************************************/


/**********************************************************************************/
                            /*My Protocol to send And receive*/
void UART_voidSendStringMyProtocol(u8 *str)
{
    u8 lens=0,sum=0,i=0;
    while(str[lens]!='\0')
    {
        sum+=str[lens];
        lens++;
    }
    UART_voidSendByteSynchBlocking(lens);

    while(str[i]!='\0')
    {
        UART_voidSendByteSynchBlocking(str[i]);
    }
    UART_voidSendByteSynchBlocking((u8)sum);
    UART_voidSendByteSynchBlocking((u8)(sum >> 8));
}

u8 UART_voidReceiveStringMyProtocol(u8 *str)
{
    u8 i, lens = UART_u8ReadByteSynchBlocking();
    u16 sum_rec=0,sum_cal=0;
    u8 first_byte,second_byte;

    for(i=0;i<lens;i++)
    {
        str[i] = UART_u8ReadByteSynchBlocking();
        sum_cal+=str[i];
    }
    first_byte = UART_u8ReadByteSynchBlocking();
    second_byte = UART_u8ReadByteSynchBlocking();
    sum_cal=first_byte | (second_byte<<8);
    if(sum_cal == sum_rec) return 1;
    return 0;
}

/**********************************************************************************/
u8 UART_u8Frame(u8 *str, u8 *s1, u8 *s2, u8 *pnum1, u8 *pnum2)
{
	//our frame: hello,509,hi,76
	
	u8 i=0,flag=0,j=0,k=0;
	u16 num1,num2;
	
	while(str[i]!='\0')
	{
		if(str[i]==',') flag++;
		else
		{
			if(flag==0)
			{
				s1[j]=str[i];
				j++; 
			}
			else if(flag==1)
			{
				if(str[i] >='0' && str[i] <='9')
				{
					num1=num1*10+(str[i]-'0');
				}
			}
			else if(flag==2)
			{
				s2[k]=str[i];
				k++; 
			}
			else if(flag==3) num2=num2*10+(str[i]-'0');
		}
		i++;
	}
	s1[j]='\0';
	s2[k]='\0';
	*pnum1=num1;
	*pnum2=num2;
	if(flag!=3) return 0;
	return 1;
}

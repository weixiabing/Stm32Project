#ifndef __MYSPI_H__
#define __MYSPI_H__
void MySPI_Init(void);

void MySPI_Start(void);
void MyySPI_Stop(void);
uint8_t MySPI_SwapByte(uint8_t ByteSend);
#endif // !__MYSPI_H__

/**********************************************************************
Copyright:		YiXiong AUTO S&T Co., Ltd.
Description:	声明故障码数据处理函数
History:
	<author>	<time>		<desc>

************************************************************************/
#ifndef _DTC_LIB_H
#define _DTC_LIB_H
#include "../interface/protocol_define.h"

enum READ_CURRENT_DTC_TYPE
{
    GENERAL_CURRENT_DTC = 0,
    SEA1939_CURRENT_DTC,
	SPECIAL_CURRENT_DTC,

};

enum READ_HISTORY_DTC_TYPE
{
    GENERAL_HISTORY_DTC = 0,
	SEA1939_HISTORY_DTC,
};

int process_Dtc_data( byte* pcDctData, int iValidLen, void* pOut, byte cDtcMask, bool bFunction);
//车辆自诊断
int process_self_Dtc_data( byte* pcDctData, int iValidLen,int cDtcStartOffset,int cDtcBytesInCmd ,
						  int cStatusOffset,int cDtcBytesInDisplay, byte cDtcMask, void* pOut);
int big_to_small(int c);
int New_special_return_status( const byte cTipMode, const byte* pcLable, const byte* pcTipContent, byte cButtonNum, void* pOut );
int New_add_data_and_controlsID( const int iAppendDataOffset, const byte* pcData, const byte cDataLen,
							const int iUploadDataType, const byte* pcControlsID, void* pOut );

int process_SEA_1939_Dtc_data( byte* pcDctData, int iValidLen, void* pOut, byte cDtcMask );
void process_read_current_Dtc( void* pIn, void* pOut );
void process_read_history_Dtc( void* pIn, void* pOut );
void process_general_read_current_Dtc( void* pIn, void* pOut );
void process_special_read_current_Dtc( void* pIn, void* pOut );
void process_general_read_history_Dtc( void* pIn, void* pOut );
//void process_read_single_line_can_current_Dtc( void* pIn, void* pOut );
void process_SEA1939_read_current_Dtc( void* pIn, void* pOut );
void process_SEA1939_general_read_history_Dtc( void* pIn, void* pOut );
#endif


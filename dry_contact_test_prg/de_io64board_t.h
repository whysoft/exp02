
#ifndef K1_de_io64board_t_H
#define K1_de_io64board_t_H


#include "2.h"



//  
class de_io64board_t  
{
public:
	WCrsc	m_lckDev;

public:
	wl::tuint8		m_output_reg;			//  	relay command �̵�������	0=enable 
	wl::tuint8		m_input_reg;			//  	read dig-input ��ȡ����ӵ�	0=enable 
	 				
public:
	de_io64board_t();
	virtual ~de_io64board_t();

public:
	tbool OpenCom( std::string strConnString );
	tbool SyncValue();

};

 


#endif




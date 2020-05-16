//
#include "2.h"
#include "de_io64board_t.h"



//
class SerialPort_t : public WComeliCell
{
public:
	//
	SerialPort_t()
	{
	}

	//
	virtual ~SerialPort_t()
	{
	}
};

 
SerialPort_t  sp;


//
de_io64board_t::de_io64board_t()
{
	m_output_reg = m_input_reg = 0xff;
}



//
de_io64board_t::~de_io64board_t()
{
}

 

// 
tbool de_io64board_t::OpenCom( std::string strConnString )
{
	MYAUTOLOCK(m_lckDev);
	WComeliCell *psp = NULL;

	psp = &sp;

	if( !psp->Conn(strConnString) )
	{
		std::cout << strConnString << " , connection fail." << std::endl;
		return 0;
	}

	std::cout << strConnString << " , connection ok." << std::endl;
	return 1;

}



// 
tbool de_io64board_t::SyncValue()
{
	MYAUTOLOCK(m_lckDev);
	WComeliCell *psp = NULL;
	
	psp = &sp;

	std::string s1;
	SCake ck;

	s1  = "FF 00 01 02 03 04 05 06 ";	 
	s1 += "81 ";	 
	ck.UnSeri3( s1 );
	ck.redim( 64, 1 );
	ck.buf()[9] = this->m_output_reg;
	ck.buf()[63] = std::accumulate( ck.buf(), ck.buf() + 63, (tuint8)0 );
	psp->send_bin( ck ); 

	ck.redim(0);
	psp->recv_len( ck , 64 );
	if( ck.len() != 64 )
	{
		return 0;
	}

	this->m_input_reg = (tuint8)ck.buf()[9];
	this->m_output_reg = (tuint8)ck.buf()[10];

	return 1;
}



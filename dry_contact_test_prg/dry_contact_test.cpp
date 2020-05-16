//
#include "2.h"
#include "de_io64board_t.h"



// 
bool IsOsWin()
{
#ifdef WINENV_
	return true;
#else
	return false;
#endif
}




//
int main(int argc, char* argv[])
{
	de_io64board_t  iobd;
	std::string strConn;
	WFile fl;

	fl.bind( "dry_contact_test.config.txt" );
	fl.read_str( strConn );
	 
	std::cout << "looking for the config file: " << fl << std::endl;

	// open the com port
	if( ! iobd.OpenCom( strConn ) )
	{
		std::cout << "Cannot open com port. exit." << std::endl;
		goto PRG_END;
	}

	while(1)
	{
		iobd.SyncValue();
		
		std::cout << "  relay_value=" << std::setbase(16) << std::setfill('0') << std::setw(2) << std::setiosflags(std::ios::uppercase) << (int)iobd.m_output_reg << std::endl;
		std::cout << "  input_dig_value=" << std::setbase(16) << std::setfill('0') << std::setw(2) << std::setiosflags(std::ios::uppercase) << (int)iobd.m_input_reg << std::endl;

		std::cout << "11: connect relay 1" << std::endl;
		std::cout << "12: connect relay 2" << std::endl;
		std::cout << "13: connect relay 3" << std::endl;
		std::cout << "14: connect relay 4" << std::endl;
		std::cout << "15: connect relay 5" << std::endl;
		std::cout << "16: connect relay 6" << std::endl;
		std::cout << "17: connect relay 7" << std::endl;
		std::cout << "18: connect relay 8" << std::endl;
		std::cout << "21: disconnect relay 1" << std::endl;
		std::cout << "22: disconnect relay 2" << std::endl;
		std::cout << "23: disconnect relay 3" << std::endl;
		std::cout << "24: disconnect relay 4" << std::endl;
		std::cout << "25: disconnect relay 5" << std::endl;
		std::cout << "26: disconnect relay 6" << std::endl;
		std::cout << "27: disconnect relay 7" << std::endl;
		std::cout << "28: disconnect relay 8" << std::endl;
		std::cout << "89: only read the input_dig_value" << std::endl;
		std::cout << "99: exit" << std::endl;

		int i;
		scanf( "%d", &i );

		if( i == 11 ) 	SStrf::writebit( &(iobd.m_output_reg), 7, 0 );
		if( i == 12 )	SStrf::writebit( &(iobd.m_output_reg), 6, 0 );
		if( i == 13 )	SStrf::writebit( &(iobd.m_output_reg), 5, 0 );
		if( i == 14 )	SStrf::writebit( &(iobd.m_output_reg), 4, 0 );
		if( i == 15 )	SStrf::writebit( &(iobd.m_output_reg), 3, 0 );
		if( i == 16 )	SStrf::writebit( &(iobd.m_output_reg), 2, 0 );
		if( i == 17 )	SStrf::writebit( &(iobd.m_output_reg), 1, 0 );
		if( i == 18 )	SStrf::writebit( &(iobd.m_output_reg), 0, 0 );
		if( i == 21 ) 	SStrf::writebit( &(iobd.m_output_reg), 7, 1 );
		if( i == 22 )	SStrf::writebit( &(iobd.m_output_reg), 6, 1 );
		if( i == 23 )	SStrf::writebit( &(iobd.m_output_reg), 5, 1 );
		if( i == 24 )	SStrf::writebit( &(iobd.m_output_reg), 4, 1 );
		if( i == 25 )	SStrf::writebit( &(iobd.m_output_reg), 3, 1 );
		if( i == 26 )	SStrf::writebit( &(iobd.m_output_reg), 2, 1 );
		if( i == 27 )	SStrf::writebit( &(iobd.m_output_reg), 1, 1 );
		if( i == 28 )	SStrf::writebit( &(iobd.m_output_reg), 0, 1 );
		if( i == 89 )	{}
		if( i == 99 ) break;
	}


PRG_END:
	if( IsOsWin() ) system("pause");

	return 0;
}



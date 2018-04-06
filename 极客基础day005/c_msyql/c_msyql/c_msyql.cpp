// c_msyql.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

// 1. ����ͷ�ļ��Ϳ��ļ�
// 1.1 ��mysql��includeĿ¼���õ���Ŀ�İ���Ŀ¼��.
#include <mysql.h>

#pragma comment(lib,"msyql\\lib\\libmysql.lib")



int main(int argc,char** argv)
{
	// 2. ��ʼ��mysql��
	mysql_library_init(argc,argv,nullptr );

	// 3. ��ʼ��msyql����
	MYSQL mysql = { 0 };
	MYSQL* _this = &mysql;
	mysql_init( _this );

	// 4. ʹ��msyql�������ӵ����ݿ�
	mysql_real_connect( _this ,
		"192.168.40.129" ,
		"root" ,
		"123456" ,
		"15pbChatroom" ,
		3306 ,
		0 , 0 );
	if( mysql_errno( _this ) != 0 ) {
		printf( "���ӵ�mysqlʧ��:%s\n" ,
			mysql_error( _this ) );
		return 0;
	}

	// 5. ִ��msyql���
	mysql_query( _this , "SET NAMES GBK" );
	char sql[ 300 ];
	sprintf_s( sql , 300 ,
		"insert into �û���(name,height,age,classroomid) values(\"%s\",%lf,%d,%d);" ,
		"�绨" , 1.8 , 18 , 2 );

	mysql_query( _this , sql );

	// 6. ����msyql��䷵�ؽ����
	mysql_query( _this , "select * from �û���;" );
	MYSQL_RES*   res = NULL;
	MYSQL_FIELD* pField = NULL;
	int nNumOfField = 0;
	// mysql_store_result :		ȡ������ȫ���н����
	// ȡ�������(ֻ��ȡ��һ�н����)
	//res = mysql_use_result( _this );
	res = mysql_use_result(_this);
	if( res == NULL ) {
		printf( "���ӵ�mysqlʧ��:%s\n" ,
			mysql_error( _this ) );
		return 0;
	}
	// 6.1 ����������е���
	// 6.1.1 ��ȡ�еĸ���
	nNumOfField = mysql_num_fields( res );
	// 6.1.2 ��ȡÿ�е�����
	for( int i = 0; i < nNumOfField; ++i ) {
		// ÿ��ѭ������õ�һ���ֶ�
		pField = mysql_fetch_field( res );
		printf( "%s | " , pField->name );
	}
	printf( "\n" );

	// 6.2 ����������е���
	do {
		// ������е�ÿһ��ʵ������һ��ָ�����鱣���
		// �����е�ÿ��Ԫ�ض���һ���ַ���ָ��, ÿ��ָ��
		// ָ��һ���е��е��ı�
		MYSQL_ROW pRow = mysql_fetch_row( res );
		for( int i = 0; i < nNumOfField; ++i ) {
			if( pRow[ i ] != nullptr ) {
				printf( "%s | " , pRow[ i ] );
			}
			else {
				printf( "(NULL) | " );
			}
		}
		printf( "\n" );
		mysql_free_result( res );//�ͷŽ����
	} while( (res = mysql_use_result(_this)) != NULL );


	mysql_library_end( );
    return 0;
}


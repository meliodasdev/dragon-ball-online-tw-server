﻿//***********************************************************************************
//
//	File		:	NtlAdmin.h
//
//	Begin		:	2006-04-20
//
//	Copyright	:	ⓒ NTL-Inc Co., Ltd
//
//	Author		:	Hyun Woo, Koo   ( zeroera@ntl-inc.com )
//
//	Desc		:	게임 및 서버 관리 관련
//
//***********************************************************************************
#pragma once

#include "Base.h"
#include "NtlSharedDef.h"

enum eSERVER_TEXT_TYPE
{
	SERVER_TEXT_SYSTEM,		// 채팅창에만 나오는 메시지
	SERVER_TEXT_NOTICE,		// 화면위에만 출력된다 = NOTIFY
	SERVER_TEXT_SYSNOTICE,	// 채팅창과 화면위에 같이 출력된다.
	SERVER_TEXT_EMERGENCY,	// NPC 가 나오는 연출이 있다. = NPC NOTIFY

	SERVER_TEXT_TYPE_COUNT,
};

//-----------------------------------------------------------------------------------
// GM Command
//-----------------------------------------------------------------------------------
// GM COMMAND TYPE
enum eGM_PUNISH_PASSIVE_TYPE
{
	GM_PUNISH_PASSIVE_TYPE_SILENCE,
	GM_PUNISH_PASSIVE_TYPE_BLOCK,
	GM_PUNISH_PASSIVE_TYPE_USER_BLOCK,
	GM_PUNISH_PASSIVE_TYPE_ATTACK,
	GM_PUNISH_PASSIVE_TYPE_TEMPORARY,
	
	GM_PUNISH_PASSIVE_TYPE_COUNT,
	GM_PUNISH_PASSIVE_TYPE_FIRST = GM_PUNISH_PASSIVE_TYPE_SILENCE,
	GM_PUNISH_PASSIVE_TYPE_LAST  = GM_PUNISH_PASSIVE_TYPE_TEMPORARY,
};

enum eGM_USE_PASSIVE_TYPE
{
	GM_USE_PASSIVE_TYPE_HIDE,
	GM_USE_PASSIVE_TYPE_SUPER,
	GM_USE_PASSIVE_TYPE_IGNORE,
	GM_USE_PASSIVE_TYPE_ALL_CONNECT,
	GM_USE_PASSIVE_TYPE_NEVER_KICK,
	
	GM_USE_PASSIVE_TYPE_COUNT,

	GM_USE_PASSIVE_TYPE_FIRST = GM_USE_PASSIVE_TYPE_HIDE,
	GM_USE_PASSIVE_TYPE_LAST  = GM_USE_PASSIVE_TYPE_COUNT - 1,
};
/*
enum eGM_USE_TYPE
{
	GM_USE_TYPE_SILENCE,
	GM_USE_TYPE_BLOCK,
	GM_USE_TYPE_ATTACK,

	GM_USE_TYPE_HIDE,
	GM_USE_TYPE_SUPER,
	
	GM_USE_TYPE_NOTICE,
	GM_USE_TYPE_EXP,
	GM_USE_TYPE_CREATE,
	GM_USE_TYPE_MONEY,
	GM_USE_TYPE_WHERE,
	GM_USE_TYPE_VISIT,
	GM_USE_TYPE_MOVE,
	GM_USE_TYPE_RECALL,
	GM_USE_TYPE_KICK,

	GM_USE_TYPE_COUNT,

	GM_USE_TYPE_FIRST = GM_USE_TYPE_SILENCE,
	GM_USE_TYPE_LAST  = GM_USE_TYPE_KICK,
};
// GM Ability Flag
enum eGM_USE_FLAG
{
	GM_USE_FLAG_SILENCE			= 0x01 << GM_USE_TYPE_SILENCE ,
	GM_USE_FLAG_BLOCK			= 0x01 << GM_USE_TYPE_BLOCK ,
	GM_USE_FLAG_ATTACK			= 0x01 << GM_USE_TYPE_ATTACK ,

	GM_USE_FLAG_HIDE			= 0x01 << GM_USE_TYPE_HIDE ,
	GM_USE_FLAG_SUPER			= 0x01 << GM_USE_TYPE_SUPER ,
	
	GM_USE_FLAG_NOTICE			= 0x01 << GM_USE_TYPE_NOTICE ,
	GM_USE_FLAG_EXP				= 0x01 << GM_USE_TYPE_EXP ,
	GM_USE_FLAG_CREATE			= 0x01 << GM_USE_TYPE_CREATE ,
	GM_USE_FLAG_MONEY			= 0x01 << GM_USE_TYPE_MONEY ,
	GM_USE_FLAG_WHERE			= 0x01 << GM_USE_TYPE_WHERE ,
	GM_USE_FLAG_VISIT			= 0x01 << GM_USE_TYPE_VISIT ,
	GM_USE_FLAG_MOVE			= 0x01 << GM_USE_TYPE_MOVE ,
	GM_USE_FLAG_RECALL			= 0x01 << GM_USE_TYPE_RECALL ,
	GM_USE_FLAG_KICK			= 0x01 << GM_USE_TYPE_KICK 
	
};

const DWORD GM_USE_LEVEL1_FLAG = GM_USE_FLAG_SILENCE + GM_USE_FLAG_BLOCK + GM_USE_FLAG_ATTACK + GM_USE_FLAG_HIDE + GM_USE_FLAG_SUPER + GM_USE_FLAG_NOTICE + GM_USE_FLAG_EXP + GM_USE_FLAG_CREATE + GM_USE_FLAG_MONEY + GM_USE_FLAG_WHERE + GM_USE_FLAG_VISIT + GM_USE_FLAG_MOVE + GM_USE_FLAG_RECALL + GM_USE_FLAG_KICK;
// 모든 기능을 제한 없이 사용 가능
const DWORD GM_USE_LEVEL2_FLAG = GM_USE_TYPE_HIDE + GM_USE_TYPE_SUPER + GM_USE_FLAG_NOTICE + GM_USE_FLAG_WHERE + GM_USE_FLAG_VISIT + GM_USE_FLAG_MOVE + GM_USE_FLAG_RECALL;
// 제재를 제외한 기능
*/
struct sPUNISH_DATA
{
	BYTE	byPunishType;
	int		nRemainTime;
};

struct sPUNISH_DATA_TEMP		// Conneting User 를 위한 데이터
{
	BYTE	byPunishType;
	DWORD   dwRemainTime;
	bool	bIsOn;
};

struct sPUNISH_CONNECTING_DATA		// Conneting User 를 위한 데이터
{
	sPUNISH_DATA_TEMP sData[GM_PUNISH_PASSIVE_TYPE_COUNT];
};

struct sBLOCK_STRING_DATA
{
	char	achData[MAX_SIZE_CHAR_NAME + 1];
};
//  블록스트링 한번에 보내는 최대 갯수 정의
const int           BLOCK_STRING_MAX			= 1000;
const int           BLOCK_STRING_BUFFER_MAX		= 5000;
//  길드 로딩 최대 갯수
const DWORD         GUILD_LOAD_BUFFER_MAX		= 500;

enum eADMIN_LEVEL
{
	ADMIN_LEVEL_NONE  = 0,
	ADMIN_LEVEL_ADMIN,
	ADMIN_LEVEL_MANAGER,
	ADMIN_LEVEL_OPERATER,
	ADMIN_LEVEL_TESTER,
	
	ADMIN_LEVEL_COUNT = ADMIN_LEVEL_TESTER - 1,

	ADMIN_LEVEL_FIRST = ADMIN_LEVEL_ADMIN,
	ADMIN_LEVEL_LAST = ADMIN_LEVEL_TESTER,
};
enum eADMIN_LEVEL_FLAG
{
	ADMIN_LEVEL_FLAG_ADMIN     = ( MAKE_BIT_FLAG(ADMIN_LEVEL_ADMIN) + MAKE_BIT_FLAG(ADMIN_LEVEL_MANAGER) + MAKE_BIT_FLAG(ADMIN_LEVEL_OPERATER) + MAKE_BIT_FLAG(ADMIN_LEVEL_TESTER) ), 
	ADMIN_LEVEL_FLAG_MANAGER   = ( MAKE_BIT_FLAG(ADMIN_LEVEL_MANAGER) + MAKE_BIT_FLAG(ADMIN_LEVEL_OPERATER) + MAKE_BIT_FLAG(ADMIN_LEVEL_TESTER) ),							  
	ADMIN_LEVEL_FLAG_OPERATER  = ( MAKE_BIT_FLAG(ADMIN_LEVEL_OPERATER) + MAKE_BIT_FLAG(ADMIN_LEVEL_TESTER) ),														      
	ADMIN_LEVEL_FLAG_TESTER    = MAKE_BIT_FLAG(ADMIN_LEVEL_TESTER)																							  
};

enum ePUNISH_QUERY
{
	PUNISH_QUERY_ACCOUNTID,			// 계정에 사용
	PUNISH_QUERY_USERNAME,			// 계정에 사용
	PUNISH_QUERY_CHARID,			// 캐릭터에만 한정 사용
	PUNISH_QUERY_CHARNAME,			// 캐릭터에만 한정 사용

	PUNISH_QUERY_COUNT,

	PUNISH_QUERY_FIRST = PUNISH_QUERY_ACCOUNTID,
	PUNISH_QUERY_LAST  = PUNISH_QUERY_CHARNAME,
};

// 최대 제재 이유 문자열 길이
const int MAX_PUNISH_REASON_LENGTH = 512;
const int MAX_SIZE_PUNISH_REASON_BUFFER_MULTIBYTE = 2048;

const DWORD REPORT_LOAD_INTERVAL_IN_MILLISECS = 10 * 1000;
const DWORD DBO_REPORT_PLAYER_COUNT_IN_MILLISECS = 2 * 60 * 1000;
﻿/*	@(#)Copyright (C) H.Shirouzu 1996-2017   ipmsg.h	Ver4.50 */
/* ========================================================================
	Project  Name			: IP Messenger for Win32
	Module Name				: Protocol Header
	Create					: 1996-06-01(Sat)
	Update					: 2017-06-12(Mon)
	Copyright				: H.Shirouzu
	Reference				: 
	======================================================================== */

#ifndef IPMSG_H
#define IPMSG_H

#include "environ.h"

/*  IP Messenger Communication Protocol version 3.0 define  */
/*  macro  */
#define GET_MODE(command)	(command & 0x000000ffUL)
#define GET_OPT(command)	(command & 0xffffff00UL)

/*  header  */
#define IPMSG_VERSION			0x0001
#define IPMSG_NEW_VERSION		0x0003
#define IPMSG_DEFAULT_PORT		0x0979

/*  command  */
#define IPMSG_NOOPERATION		0x00000000UL

#define IPMSG_BR_ENTRY			0x00000001UL
#define IPMSG_BR_EXIT			0x00000002UL
#define IPMSG_ANSENTRY			0x00000003UL
#define IPMSG_BR_ABSENCE		0x00000004UL
#define IPMSG_BR_NOTIFY			IPMSG_BR_ABSENCE

#define IPMSG_BR_ISGETLIST		0x00000010UL
#define IPMSG_OKGETLIST			0x00000011UL
#define IPMSG_GETLIST			0x00000012UL
#define IPMSG_ANSLIST			0x00000013UL
#define IPMSG_ANSLIST_DICT		0x00000014UL
#define IPMSG_BR_ISGETLIST2		0x00000018UL

#define IPMSG_SENDMSG			0x00000020UL
#define IPMSG_RECVMSG			0x00000021UL
#define IPMSG_READMSG			0x00000030UL
#define IPMSG_DELMSG			0x00000031UL
#define IPMSG_ANSREADMSG		0x00000032UL

#define IPMSG_GETINFO			0x00000040UL
#define IPMSG_SENDINFO			0x00000041UL

#define IPMSG_GETABSENCEINFO	0x00000050UL
#define IPMSG_SENDABSENCEINFO	0x00000051UL

#define IPMSG_GETFILEDATA		0x00000060UL
#define IPMSG_RELEASEFILES		0x00000061UL
#define IPMSG_GETDIRFILES		0x00000062UL
#define IPMSG_DIRFILES_AUTH		0x00000063UL
#define IPMSG_DIRFILES_AUTHRET	0x00000064UL

#define IPMSG_GETPUBKEY			0x00000072UL
#define IPMSG_ANSPUBKEY			0x00000073UL

#define IPMSG_AGENT_REQ			0x000000a0UL
#define IPMSG_AGENT_ANSREQ		0x000000a1UL
#define IPMSG_AGENT_PACKET		0x000000a2UL
#define IPMSG_AGENT_PROXYREQ	0x000000a3UL

#define IPMSG_DIR_POLL			0x000000b0UL
#define IPMSG_DIR_POLLAGENT		0x000000b1UL
#define IPMSG_DIR_BROADCAST		0x000000b2UL
#define IPMSG_DIR_ANSBROAD		0x000000b3UL
#define IPMSG_DIR_PACKET		0x000000b4UL
#define IPMSG_DIR_REQUEST		0x000000b5UL
#define IPMSG_DIR_AGENTPACKET	0x000000b6UL
#define IPMSG_DIR_EVBROAD		0x000000b7UL
#define IPMSG_DIR_AGENTREJECT	0x000000b8UL

/*  option for all command  */
#define IPMSG_ABSENCEOPT		0x00000100UL
#define IPMSG_SERVEROPT			0x00000200UL
#define IPMSG_DIALUPOPT			0x00010000UL
#define IPMSG_FILEATTACHOPT		0x00200000UL
#define IPMSG_ENCRYPTOPT		0x00400000UL
#define IPMSG_UTF8OPT			0x00800000UL
#define IPMSG_CAPUTF8OPT		0x01000000UL
#define IPMSG_ENCEXTMSGOPT		0x04000000UL
#define IPMSG_CLIPBOARDOPT		0x08000000UL
#define IPMSG_CAPFILEENC_OBSLT	0x00001000UL
#define IPMSG_CAPFILEENCOPT		0x00040000UL
#define IPMSG_CAPIPDICTOPT		0x02000000UL
#define IPMSG_DIR_MASTER		0x10000000UL
#define IPMSG_FLAG_RESV1		0x20000000UL
#define IPMSG_FLAG_RESV2		0x40000000UL
//#define IPMSG_FLAG_RESV3		0x80000000UL 

#define IPMSG_ALLSTAT	(IPMSG_ABSENCEOPT|IPMSG_SERVEROPT|IPMSG_DIALUPOPT|IPMSG_FILEATTACHOPT \
						 |IPMSG_CLIPBOARDOPT|IPMSG_ENCRYPTOPT|IPMSG_CAPUTF8OPT \
						 |IPMSG_ENCEXTMSGOPT|IPMSG_CAPFILEENCOPT \
						 |IPMSG_CAPIPDICTOPT|IPMSG_DIR_MASTER)

#define IPMSG_FULLSTAT	(IPMSG_ALLSTAT & ~(IPMSG_ABSENCEOPT|IPMSG_SERVEROPT|IPMSG_DIALUPOPT))
/*  option for SENDMSG command  */
#define IPMSG_SENDCHECKOPT		0x00000100UL
#define IPMSG_SECRETOPT			0x00000200UL
#define IPMSG_BROADCASTOPT		0x00000400UL
#define IPMSG_MULTICASTOPT		0x00000800UL
#define IPMSG_AUTORETOPT		0x00002000UL
#define IPMSG_RETRYOPT			0x00004000UL
#define IPMSG_PASSWORDOPT		0x00008000UL
#define IPMSG_NOLOGOPT			0x00020000UL
#define IPMSG_NOADDLISTOPT		0x00080000UL
#define IPMSG_READCHECKOPT		0x00100000UL
#define IPMSG_SECRETEXOPT		(IPMSG_READCHECKOPT|IPMSG_SECRETOPT)

/*  option for GETDIRFILES/GETFILEDATA command  */
#define IPMSG_ENCFILE_OBSLT		0x00000400UL
#define IPMSG_ENCFILEOPT		0x00000800UL

/*  obsolete option for send command  */
#define IPMSG_NEWMULTI_OBSLT	0x00040000UL

/* encryption/capability flags for encrypt command */
#define IPMSG_RSA_1024			0x00000002UL
#define IPMSG_RSA_2048			0x00000004UL
#define IPMSG_RSA_4096			0x00000008UL
#define IPMSG_BLOWFISH_128		0x00020000UL
#define IPMSG_AES_256			0x00100000UL
#define IPMSG_COMMON_KEYS		(IPMSG_BLOWFISH_128|IPMSG_AES_256)
#define IPMSG_PACKETNO_IV		0x00800000UL
#define IPMSG_IPDICT_CTR		0x00400000UL
#define IPMSG_ENCODE_BASE64		0x01000000UL
#define IPMSG_NOENC_FILEBODY	0x04000000UL	// noencode for file-body
#define IPMSG_SIGN_SHA1			0x20000000UL
#define IPMSG_SIGN_SHA256		0x40000000UL

/* compatibilty for Win beta version */
#define IPMSG_RSA_512OBSOLETE	0x00000001UL
#define IPMSG_RC2_40OLD			0x00000010UL	// for beta1-4 only
#define IPMSG_RC2_128OLD		0x00000040UL	// for beta1-4 only
#define IPMSG_BLOWFISH_128OLD	0x00000400UL	// for beta1-4 only
#define IPMSG_RC2_40OBSOLETE	0x00001000UL
#define IPMSG_RC2_128OBSOLETE	0x00004000UL
#define IPMSG_RC2_256OBSOLETE	0x00008000UL
#define IPMSG_BLOWFISH_256OBSOL	0x00040000UL
#define IPMSG_AES_128OBSOLETE	0x00080000UL
#define IPMSG_SIGN_MD5OBSOLETE	0x10000000UL
#define IPMSG_UNAMEEXTOPT_OBSLT	0x02000000UL

/* file types for fileattach command */
#define IPMSG_FILE_REGULAR		0x00000001UL
#define IPMSG_FILE_DIR			0x00000002UL
#define IPMSG_FILE_RETPARENT	0x00000003UL	// return parent directory
#define IPMSG_FILE_SYMLINK		0x00000004UL
#define IPMSG_FILE_CDEV			0x00000005UL	// for UNIX
#define IPMSG_FILE_BDEV			0x00000006UL	// for UNIX
#define IPMSG_FILE_FIFO			0x00000007UL	// for UNIX
#define IPMSG_FILE_RESFORK		0x00000010UL	// for Mac
#define IPMSG_FILE_CLIPBOARD	0x00000020UL	// for Windows Clipboard

/* file attribute options for fileattach command */
#define IPMSG_FILE_RONLYOPT		0x00000100UL
#define IPMSG_FILE_HIDDENOPT	0x00001000UL
#define IPMSG_FILE_EXHIDDENOPT	0x00002000UL	// for MacOS X
#define IPMSG_FILE_ARCHIVEOPT	0x00004000UL
#define IPMSG_FILE_SYSTEMOPT	0x00008000UL

/* extend attribute types for fileattach command */
#define IPMSG_FILE_UID			0x00000001UL
#define IPMSG_FILE_USERNAME		0x00000002UL	// uid by string
#define IPMSG_FILE_GID			0x00000003UL
#define IPMSG_FILE_GROUPNAME	0x00000004UL	// gid by string
#define IPMSG_FILE_CLIPBOARDPOS	0x00000008UL	// 
#define IPMSG_FILE_PERM			0x00000010UL	// for UNIX
#define IPMSG_FILE_MAJORNO		0x00000011UL	// for UNIX devfile
#define IPMSG_FILE_MINORNO		0x00000012UL	// for UNIX devfile
#define IPMSG_FILE_CTIME		0x00000013UL	// for UNIX
#define IPMSG_FILE_MTIME		0x00000014UL
#define IPMSG_FILE_ATIME		0x00000015UL
#define IPMSG_FILE_CREATETIME	0x00000016UL
#define IPMSG_FILE_CREATOR		0x00000020UL	// for Mac
#define IPMSG_FILE_FILETYPE		0x00000021UL	// for Mac
#define IPMSG_FILE_FINDERINFO	0x00000022UL	// for Mac
#define IPMSG_FILE_ACL			0x00000030UL
#define IPMSG_FILE_ALIASFNAME	0x00000040UL	// alias fname

#define FILELIST_SEPARATOR		'\a'
#define HOSTLIST_SEPARATOR		'\a'
#define HOSTLIST_SEPARATORS		"\a"
#define HOSTLIST_NEW_SEPARATOR	'\f'
#define HOSTLIST_DUMMY			"\b"

#define IPMSG_DEFAULT_MULTICAST_ADDR6	"ff15::979"
#define LINK_MULTICAST_ADDR6			"ff02::1"
#define IPMSG_LIMITED_BROADCAST			"255.255.255.255"

//#define IPMSG_MULTICAST_ADDR4	"224.9.7.9"

#ifdef _WIN64
#define IPMSG_VER_WIN_TYPE		IPMSG_VER_WIN64_TYPE
#else
#define IPMSG_VER_WIN_TYPE		IPMSG_VER_WIN32_TYPE
#endif

#define IPMSG_VER_WIN32_TYPE	0x00010001
#define IPMSG_VER_WIN64_TYPE	0x00010002
#define IPMSG_VER_MAC_TYPE		0x00020000
#define IPMSG_VER_IOS_TYPE		0x00030000
#define IPMSG_VER_ANDROID_TYPE	0x00040000

/* New Protocol Key */
#define IPMSG_VER_KEY		"VER"
#define IPMSG_PKTNO_KEY		"PKT"
#define IPMSG_DATE_KEY		"DATE"
#define IPMSG_UID_KEY		"UID"
#define IPMSG_HOST_KEY		"HID"
#define IPMSG_NICK_KEY		"NCK"
#define IPMSG_NICKORG_KEY	"NCKO"
#define IPMSG_GROUP_KEY		"GRP"
#define IPMSG_STAT_KEY		"STAT"
#define IPMSG_EXSTAT_KEY	"EXST"
#define IPMSG_CMD_KEY		"CMD"
#define IPMSG_FLAGS_KEY		"FLG"
#define IPMSG_CLIVER_KEY	"CVER"
#define IPMSG_BODY_KEY		"BODY"
#define IPMSG_REPLYPKT_KEY	"RPN"
#define IPMSG_TOLIST_KEY	"TLST"
#define IPMSG_FROM_KEY		"FROM"
#define IPMSG_HOSTLIST_KEY	"HLST"
#define IPMSG_IPADDR_KEY	"IPAD"
#define IPMSG_PORT_KEY		"PORT"
#define IPMSG_POLL_KEY		"POLL"
#define IPMSG_ENCFLAG_KEY	"EF"
#define IPMSG_ENCIV_KEY		"EI"
#define IPMSG_ENCKEY_KEY	"EK"
#define IPMSG_ENCBODY_KEY	"EB"
#define IPMSG_PUB_E_KEY		"PUBE"
#define IPMSG_PUB_N_KEY		"PUBN"
#define IPMSG_ENCCAPA_KEY	"EC"
#define IPMSG_SIGN_KEY		"SIGN"

#define IPMSG_FILE_KEY		"FILE"
#define IPMSG_FID_KEY		"FI"
#define IPMSG_FNAME_KEY		"FN"
#define IPMSG_FSIZE_KEY		"FS"
#define IPMSG_MTIME_KEY		"MT"
#define IPMSG_FATTR_KEY		"FA"
#define IPMSG_CLIPPOS_KEY	"CP"

#define IPMSG_START_KEY		"START"
#define IPMSG_TOTAL_KEY		"TOTAL"
#define IPMSG_NUM_KEY		"NUM"
#define IPMSG_DIRBROAD_KEY	"DRB"
#define IPMSG_TARGADDR_KEY	"TADR"	// 192.168.0.1
#define IPMSG_NADDR_KEY		"NADR"	// 192.168.0.1/24
#define IPMSG_NADDRS_KEY	"NADRS"
#define IPMSG_ADDR_KEY		"ADR"
#define IPMSG_MASK_KEY		"MASK"
#define IPMSG_WRAPPED_KEY	"WAPD"
#define IPMSG_UPTIME_KEY	"UPT"
#define IPMSG_AGENTSEC_KEY	"AGS"
#define IPMSG_ACTIVE_KEY	"ACT"
#define IPMSG_SVRADDR_KEY	"SVADR"
#define IPMSG_AGENT_KEY		"AGNT"
#define IPMSG_DIRECT_KEY	"DRCT"

#define IPMSG_ABSTITLE_KEY	"ABST"
#define IPMSG_ABSMODE_KEY	"ABSMD"
#define IPMSG_FILELIST_KEY	"FLS"
#define IPMSG_ERRINFO_KEY	"EINF"

/*  end of IP Messenger Communication Protocol version 3.0 define  */

#ifdef IPMSG_PRO
#define IPMSG_HEAD
#include "ipmsgext.dat"
#undef  IPMSG_HEAD
#endif

#include "ipmsgcmn.h"

#endif


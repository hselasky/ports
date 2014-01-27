# Ports collection makefile for: isdn4bsd-kmod
# Date created: Feb 29 2012
# Whom:
#
# $FreeBSD$
#

PORTNAME=	isdn4bsd-utils
PORTVERSION=	2.0.9
DISTNAME=	isdn4bsd-${PORTVERSION}
CATEGORIES=	comms kld
MASTER_SITES=	http://www.selasky.org/hans_petter/distfiles/ \
		http://home.selasky.org:8192/distfiles/

MAINTAINER=	hselasky@FreeBSD.org
COMMENT=	ISDN4BSD utilities

LICENSE=	BSD

LIB_DEPENDS=    capi20.1:${PORTSDIR}/comms/libcapi

USE_RC_SUBR=	isdnd
USE_BZIP2=	yes
NO_STAGE=	yes
BINDIR=		${PREFIX}/sbin
LIBDIR=		${PREFIX}/lib
INCLUDEDIR=	${PREFIX}/include
MANDIR=		${PREFIX}/man/man
NO_MANCOMPRESS=	yes
USE_LDCONFIG=	yes
MAKE_JOBS_SAFE= yes

MAKE_ARGS=	LOCALBASE=${LOCALBASE} \
		BINDIR=${BINDIR} \
		LIBDIR=${LIBDIR} \
		MANDIR=${MANDIR} \
		INCLUDEDIR=${INCLUDEDIR}

OPTIONS_DEFINE= CAPIMONITOR CAPITEST DEBUG DTMFDECODE EXTERNAL_MONITOR \
    G711CONV ISDNCONFIG ISDND ISDNDEBUG ISDNDECODE ISDNMONITOR \
    ISDNTEL ISDNTELCTL ISDNTEST ISDNTRACE NOTCPIP_MONITOR \
    WITHOUT_CURSES

OPTIONS_DEFAULT= CAPITEST ISDNCONFIG ISDNDECODE \
    ISDNTRACE NOTCPIP_MONITOR

CAPIMONITOR_DESC=Build capimonitor utility
CAPITEST_DESC=Build capitest utility
DEBUG_DESC=Build with debugging support
DTMFDECODE_DESC=Build dtmfdecode utility
EXTERNAL_MONITOR_DESC=External ISDND monitor
G711CONV_DESC=Build g711conv utility
ISDNCONFIG_DESC=Build isdnconfig utility
ISDNDEBUG_DESC=Build isdndebug utility
ISDNDECODE_DESC=Build isdndecode utility
ISDND_DESC=Build isdnd utility
ISDNMONITOR_DESC=Build isdnmonitor utility
ISDNTELCTL_DESC=Build isdntelctl utility
ISDNTEL_DESC=Build isdntel utility
ISDNTEST_DESC=Build isdntest utility
ISDNTRACE_DESC=Build isdntrace utility
NOTCPIP_MONITOR_DESC=No TCP/IP ISDND monitor
WITHOUT_CURSES_DESC=Build utilities without curses

.include <bsd.port.pre.mk>

MAKE_ARGS+=" HAVE_UTILS=YES"

.if ${PORT_OPTIONS:MCAPIMONITOR}
I4B_CONFIG+=	HAVE_CAPIMONITOR=YES
PLIST_FILES+=	sbin/capimonitor
.endif

.if ${PORT_OPTIONS:MCAPITEST}
I4B_CONFIG+=	HAVE_CAPITEST=YES
MAN8+=		capitest.8.gz
PLIST_FILES+=	sbin/capitest
.endif

.if ${PORT_OPTIONS:MDTMFDECODE}
I4B_CONFIG+=	HAVE_DTMFDECODE=YES
MAN1+=		dtmfdecode.1.gz
PLIST_FILES+=	sbin/dtmfdecode
.endif

.if ${PORT_OPTIONS:MG711CONV}
I4B_CONFIG+=	HAVE_G711CONV=YES
MAN1+=		g711conv.1.gz
PLIST_FILES+=	sbin/g711conv
.endif

.if ${PORT_OPTIONS:MISDNCONFIG}
I4B_CONFIG+=	HAVE_ISDNCONFIG=YES
MAN8+=		isdnconfig.8.gz
PLIST_FILES+=	sbin/isdnconfig
.endif

.if ${PORT_OPTIONS:MISDNDEBUG}
I4B_CONFIG+=	HAVE_ISDNDEBUG=YES
MAN8+=		isdndebug.8.gz
PLIST_FILES+=	sbin/isdndebug
.endif

.if ${PORT_OPTIONS:MISDNDECODE}
I4B_CONFIG+=	HAVE_ISDNDECODE=YES
MAN8+=		isdndecode.8.gz
PLIST_FILES+=	sbin/isdndecode
.endif

.if ${PORT_OPTIONS:MISDND}
I4B_CONFIG+=	HAVE_ISDND=YES
MAN5+=		isdnd.acct.5.gz isdnd.rates.5.gz isdnd.rc.5.gz
MAN8+=		isdnd.8.gz
PLIST_FILES+=	sbin/isdnd
.endif

.if ${PORT_OPTIONS:MISDNMONITOR}
I4B_CONFIG+=	HAVE_ISDNMONITOR=YES
MAN8+=		isdnmonitor.8.gz
PLIST_FILES+=	sbin/isdnmonitor
.endif

.if ${PORT_OPTIONS:MISDNTELCTL}
I4B_CONFIG+=	HAVE_ISDNTELCTL=YES
MAN8+=		isdntelctl.8.gz
PLIST_FILES+=	sbin/isdntelctl
.endif

.if ${PORT_OPTIONS:MISDNTEL}
I4B_CONFIG+=	HAVE_ISDNTEL=YES
MAN8+=		isdntel.8.gz
PLIST_FILES+=	sbin/isdntel
.endif

.if ${PORT_OPTIONS:MISDNTEST}
I4B_CONFIG+=	HAVE_ISDNTEST=YES
MAN8+=		isdntest.8.gz
PLIST_FILES+=	sbin/isdntest
.endif

.if ${PORT_OPTIONS:MISDNTRACE}
I4B_CONFIG+=	HAVE_ISDNTRACE=YES
MAN8+=		isdntrace.8.gz
PLIST_FILES+=	sbin/isdntrace
.endif

.if ${PORT_OPTIONS:MEXTERNAL_MONITOR}
I4B_CONFIG+=	I4B_EXTERNAL_MONITOR=YES
.endif

.if ${PORT_OPTIONS:MWITHOUT_CURSES}
I4B_CONFIG+=	I4B_WITHOUT_CURSES=YES
.endif

.if ${PORT_OPTIONS:MNOTCPIP_MONITOR}
I4B_CONFIG+=	I4B_NOTCPIP_MONITOR=YES
.endif

do-configure:
	${MAKE} ${MAKE_ARGS} -C ${WRKSRC} -f ${WRKSRC}/Makefile \
		${I4B_CONFIG} configure

do-install:
	${MAKE} ${MAKE_ARGS} -C ${WRKSRC} -f ${WRKSRC}/Makefile install

.if ${OSVERSION} < 800000
IGNORE=		requires FreeBSD 8.0-RELEASE or later
.endif

.include <bsd.port.post.mk>

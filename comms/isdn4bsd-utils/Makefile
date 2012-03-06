# Ports collection makefile for: isdn4bsd-kmod
# Date created: Feb 29 2012
# Whom:
#
# $FreeBSD$
#

PORTNAME=	isdn4bsd-utils
PORTVERSION=	2.0.2
DISTNAME=	isdn4bsd-${PORTVERSION}
CATEGORIES=	comms kld
MASTER_SITES=	http://www.selasky.org/hans_petter/distfiles/ \
		http://hselasky.homeunix.org:8192/distfiles/

MAINTAINER=	hselasky@FreeBSD.org
COMMENT=	ISDN4BSD utilities

USE_BZIP2=	yes

LICENSE=	BSD
BINDIR=		${PREFIX}/sbin
LIBDIR=		${PREFIX}/lib
INCLUDEDIR=	${PREFIX}/include
MANDIR=		${PREFIX}/man/man
USE_LDCONFIG=	yes
MAKE_JOBS_SAFE= yes

LIB_DEPENDS=    capi20.1:${PORTSDIR}/comms/libcapi

PLIST_SUB= \
		BINDIR="${BINDIR}" \
		LIBDIR="${LIBDIR}" \
		INCLUDEDIR="${INCLUDEDIR}" \
		MANDIR="${MANDIR}"

OPTIONS= \
		CAPIMONITOR "Build capimonitor utility" Off \
		CAPITEST "Build capitest utility" On \
		DEBUG "Build with debugging support" Off \
		DTMFDECODE "Build dtmfdecode utility" Off \
		EXTERNAL_MONITOR "External ISDND monitor" Off \
		G711CONV "Build g711conv utility" Off \
		ISDNCONFIG "Build isdnconfig utility" On \
		ISDND "Build isdnd utility" Off \
		ISDNDEBUG "Build isdndebug utility" Off \
		ISDNDECODE "Build isdndecode utility" On \
		ISDNMONITOR "Build isdnmonitor utility" Off \
		ISDNTEL "Build isdntel utility" Off \
		ISDNTELCTL "Build isdntelctl utility" Off \
		ISDNTEST "Build isdntest utility" Off \
		ISDNTRACE "Build isdntrace utility" On \
		MAN "Install manual pages" On \
		NOTCPIP_MONITOR "No TCP/IP ISDND monitor" On \
		WITHOUT_CURSES "Build utilities without curses" Off \

.include <bsd.port.pre.mk>

MAKE_ARGS+=" HAVE_UTILS=YES"

.if defined(WITH_CAPIMONITOR)
PLIST_SUB+= HAVE_CAPIMONITOR=YES
.endif
.if defined(WITH_CAPITEST)
PLIST_SUB+= HAVE_CAPITEST=YES
.endif
.if defined(WITH_DTMFDECODE)
PLIST_SUB+= HAVE_DTMFDECODE=YES
.endif
.if defined(WITH_G711CONV)
PLIST_SUB+= HAVE_G711CONV=YES
.endif
.if defined(WITH_ISDNCONFIG)
PLIST_SUB+= HAVE_ISDNCONFIG=YES
.endif
.if defined(WITH_ISDNDEBUG)
PLIST_SUB+= HAVE_ISDNDEBUG=YES
.endif
.if defined(WITH_ISDNDECODE)
PLIST_SUB+= HAVE_ISDNDECODE=YES
.endif
.if defined(WITH_ISDND)
PLIST_SUB+= HAVE_ISDND=YES
.endif
.if defined(WITH_ISDNMONITOR)
PLIST_SUB+= HAVE_ISDNMONITOR=YES
.endif
.if defined(WITH_ISDNTELCTL)
PLIST_SUB+= HAVE_ISDNTELCTL=YES
.endif
.if defined(WITH_ISDNTEL)
PLIST_SUB+= HAVE_ISDNTEL=YES
.endif
.if defined(WITH_ISDNTEST)
PLIST_SUB+= HAVE_ISDNTEST=YES
.endif
.if defined(WITH_ISDNTRACE)
PLIST_SUB+= HAVE_ISDNTRACE=YES
.endif
.if !defined(WITH_MAN)
PLIST_SUB+= HAVE_NO_MAN=YES
.endif
.if defined(WITH_EXTERNAL_MONITOR)
PLIST_SUB+= I4B_EXTERNAL_MONITOR=YES
.endif
.if defined(WITH_WITHOUT_CURSES)
PLIST_SUB+= I4B_WITHOUT_CURSES=YES
.endif
.if defined(WITH_NOTCPIP_MONITOR)
PLIST_SUB+= I4B_NOTCPIP_MONITOR=YES
.endif

do-configure:
	${MAKE} ${MAKE_ARGS} -C ${WRKSRC} -f ${WRKSRC}/Makefile \
		${PLIST_SUB} configure

do-install:
	${MAKE} ${MAKE_ARGS} -C ${WRKSRC} -f ${WRKSRC}/Makefile install

.if ${OSVERSION} < 800000
IGNORE=		requires FreeBSD 8.0-RELEASE or later
.endif

.include <bsd.port.post.mk>

# Ports collection makefile for: chan_capi
# Date created: Feb 29 2012
# Whom:
#
# $FreeBSD$
#

PORTNAME=	chan_capi
PORTVERSION=	2.0.18
CATEGORIES=	comms
MASTER_SITES=	http://www.selasky.org/hans_petter/distfiles/ \
		http://home.selasky.org:8192/distfiles/

MAINTAINER=	hselasky@FreeBSD.org
COMMENT=	CAPI channel driver for the Asterisk PBX

LICENSE=	BSD

BUILD_DEPENDS+=	libcapi>=2.0.2:${PORTSDIR}/comms/libcapi
BUILD_DEPENDS+=	asterisk:${PORTSDIR}/net/asterisk
LIB_DEPENDS=	libcapi20.so:${PORTSDIR}/comms/libcapi
RUN_DEPENDS=	asterisk:${PORTSDIR}/net/asterisk

MTREE_FILE=	${.CURDIR}/pkg-mtree

USES=		tar:bzip2 uidfix

LIBDIR=		${PREFIX}/lib/asterisk/modules
ETCDIR=		${PREFIX}/etc/asterisk
INCLUDEDIR=	${PREFIX}/include
USE_LDCONFIG=	yes
MAKE_JOBS_SAFE=	yes

OPTIONS_DEFINE=	DEBUG CLANG

CLANG_DESC=Build using clang

.include <bsd.port.options.mk>

MAKE_ARGS=	PREFIX=${PREFIX} \
		LIBDIR=${LIBDIR} \
		ETCDIR=${ETCDIR} \
	 	INCLUDEDIR=${INCLUDEDIR}

.if ${PORT_OPTIONS:MDEBUG}
MAKE_ARGS+=	HAVE_DEBUG=YES
.endif

.if ${PORT_OPTIONS:MCLANG}
MAKE_ARGS+=	CC="/usr/bin/clang"
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800000
IGNORE=		requires FreeBSD 8.0-RELEASE or later
.endif

.include <bsd.port.post.mk>

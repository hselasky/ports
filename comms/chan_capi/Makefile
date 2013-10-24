# Ports collection makefile for: chan_capi
# Date created: Feb 29 2012
# Whom:
#
# $FreeBSD$
#

PORTNAME=	chan_capi
PORTVERSION=	2.0.3
CATEGORIES=	comms
MASTER_SITES=	http://www.selasky.org/hans_petter/distfiles/ \
		http://home.selasky.org:8192/distfiles/

MAINTAINER=	hselasky@FreeBSD.org
COMMENT=	CAPI channel driver for the Asterisk PBX

LICENSE=	BSD

BUILD_DEPENDS=	asterisk:${PORTSDIR}/net/asterisk
LIB_DEPENDS=	capi20.1:${PORTSDIR}/comms/libcapi
RUN_DEPENDS=	asterisk:${PORTSDIR}/net/asterisk

USE_BZIP2=	yes
NO_STAGE=	yes

LIBDIR=		${PREFIX}/lib/asterisk/modules
ETCDIR=		${PREFIX}/etc/asterisk
INCLUDEDIR=	${PREFIX}/include
USE_LDCONFIG=	yes
MAKE_JOBS_SAFE=	yes

OPTIONS_DEFINE=	DEBUG

DEBUG_DESC=Enable debugging

.include <bsd.port.options.mk>

MAKE_ARGS=	PREFIX=${PREFIX} \
		LIBDIR=${LIBDIR} \
		ETCDIR=${ETCDIR} \
	 	INCLUDEDIR=${INCLUDEDIR}

.if defined(WITH_DEBUG)
MAKE_ARGS+=	HAVE_DEBUG=YES
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800000
IGNORE=		requires FreeBSD 8.0-RELEASE or later
.endif

.include <bsd.port.post.mk>

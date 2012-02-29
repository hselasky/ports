# Ports collection makefile for: libcapi
# Date created: Feb 29 2012
# Whom:
#
# $FreeBSD$
#

PORTNAME=	libcapi
PORTVERSION=	2.0.1
CATEGORIES=	comms
MASTER_SITES=	http://www.selasky.org/hans_petter/distfiles/ \
		http://hselasky.homeunix.org:8192/distfiles/

MAINTAINER=	hselasky@FreeBSD.org
COMMENT=	CAPI v2.0 library for use with ISDN4BSD

USE_BZIP2=	yes

LICENSE=	BSD
LIBDIR=		${PREFIX}/lib
INCLUDEDIR=	${PREFIX}/include
MANDIR=		${PREFIX}/man/man
USE_LDCONFIG=	yes
MAKE_JOBS_SAFE= yes

OPTIONS= \
		BINTEC "Build with BinTec support" Off \
		DEBUG "Enable debugging" Off \
		MAN "Install manual pages" On

.include <bsd.port.pre.mk>

MAKE_ARGS+=" HAVE_UTILS=YES"
MAKE_ARGS+=" LIBDIR=${LIBDIR}"
MAKE_ARGS+=" INCLUDEDIR=${INCLUDEDIR}"
MAKE_ARGS+=" MANDIR=${MANDIR}"

.if defined(WITH_BINTEC)
MAKE_ARGS+=" HAVE_BINTEC=YES"
.endif
.if defined(WITH_DEBUG)
MAKE_ARGS+=" HAVE_DEBUG=YES"
.endif
.if !defined(WITH_MAN)
MAKE_ARGS+=" MK_MAN=no"
.endif

.if ${OSVERSION} < 800000
IGNORE=		requires FreeBSD 8.0-RELEASE or later
.endif

.include <bsd.port.post.mk>

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
COMMENT=	ISDN CAPI v2.0 library

LICENSE=	BSD

USE_BZIP2=	yes
LIBDIR=		${PREFIX}/lib
INCLUDEDIR=	${PREFIX}/include
USE_LDCONFIG=	yes
MAKE_JOBS_SAFE=	yes

OPTIONS=	BINTEC "Build with BinTec support" Off \
		DEBUG "Enable debugging" Off \
		MAN "Install manual pages" On

.include <bsd.port.options.mk>

MAKE_ARGS=	HAVE_UTILS=YES \
		LIBDIR=${LIBDIR} \
		INCLUDEDIR=${INCLUDEDIR}

PLIST_FILES=	include/capi20.h lib/libcapi20.a lib/libcapi20.so \
		lib/libcapi20.so.1

.if defined(WITH_BINTEC)
MAKE_ARGS+=	HAVE_BINTEC=YES
.endif

.if defined(WITH_DEBUG)
MAKE_ARGS+=	HAVE_DEBUG=YES
.endif

.if defined(WITH_MAN)
MAKE_ARGS+=	HAVE_MAN=YES
NO_MANCOMPRESS=	yes
MAN3=	capi.3.gz capi20.3.gz capi20_be_alloc_bintec.3.gz \
	capi20_be_alloc_i4b.3.gz capi20_be_free.3.gz capi20_command_pack.3.gz \
	capi20_command_unpack.3.gz capi20_decode.3.gz capi20_encode.3.gz \
	capi20_fileno.3.gz capi20_get_errstr.3.gz capi20_get_manufacturer.3.gz \
	capi20_get_message.3.gz capi20_get_profile.3.gz \
	capi20_get_serial_number.3.gz capi20_get_version.3.gz \
	capi20_is_installed.3.gz capi20_put_message.3.gz capi20_register.3.gz \
	capi20_release.3.gz capi20_wait_for_message.3.gz
.else
MAKE_ARGS+=	HAVE_MAN=NO
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800000
IGNORE=		requires FreeBSD 8.0-RELEASE or later
.endif

.include <bsd.port.post.mk>

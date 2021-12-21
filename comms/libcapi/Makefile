# Ports collection makefile for: libcapi
# Date created: Feb 29 2012
# Whom:
#
# $FreeBSD$
#

PORTNAME=	libcapi
DISTVERSIONPREFIX=	v
DISTVERSION=		2.0.3
CATEGORIES=	comms

MAINTAINER=	hselasky@FreeBSD.org
COMMENT=	ISDN CAPI v2.0 library

LICENSE=	BSD2CLAUSE

USES=		tar:bzip2 uidfix
USE_GITHUB=	yes
GH_ACCOUNT=	hselasky

LIBDIR=		${PREFIX}/lib
INCLUDEDIR=	${PREFIX}/include
USE_LDCONFIG=	yes
MAKE_JOBS_SAFE=	yes

OPTIONS_DEFINE= BINTEC CLIENT DEBUG MAN
OPTIONS_DEFAULT=BINTEC CLIENT MAN

BINTEC_DESC=Build with BinTec support
CLIENT_DESC=Build with remote CAPI support
MAN_DESC=Install manual pages

.include <bsd.port.options.mk>

MAKE_ARGS=	HAVE_UTILS=YES \
		LIBDIR=${LIBDIR} \
		INCLUDEDIR=${INCLUDEDIR}

PLIST_FILES=	include/capi20.h lib/libcapi20.a lib/libcapi20.so \
		lib/libcapi20.so.1

.if ${PORT_OPTIONS:MBINTEC}
MAKE_ARGS+=	HAVE_BINTEC=YES
.endif

.if ${PORT_OPTIONS:MCLIENT}
MAKE_ARGS+=	HAVE_CAPI_CLIENT=YES
.endif

.if ${PORT_OPTIONS:MDEBUG}
MAKE_ARGS+=	HAVE_DEBUG=YES
.endif

.if ${PORT_OPTIONS:MMAN}
MAKE_ARGS+=	HAVE_MAN=YES
NO_MANCOMPRESS=	yes
MAN3=	capi.3.gz capi20.3.gz capi20_be_alloc_client.3.gz capi20_be_alloc_bintec.3.gz \
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

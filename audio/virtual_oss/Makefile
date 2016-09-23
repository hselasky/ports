# Created by: Hans Petter Selasky <hselasky@FreeBSD.org>
# $FreeBSD$

PORTNAME=	virtual_oss
PORTVERSION=	1.1.0
CATEGORIES=	audio
MASTER_SITES=	http://www.selasky.org/hans_petter/distfiles/ \
		http://home.selasky.org:8192/distfiles/

MAINTAINER=	hselasky@FreeBSD.org
COMMENT=	Virtual OSS multi device mixer application.

LICENSE=	BSD

BUILD_DEPENDS=	cuse4bsd-kmod>=0.1.24:multimedia/cuse4bsd-kmod

LIB_DEPENDS=	libcuse4bsd.so:multimedia/cuse4bsd-kmod \
		libsamplerate.so:audio/libsamplerate

USES=		tar:bzip2

OPTIONS_DEFINE=	BLUETOOTH CUSE DEBUG
OPTIONS_DEFAULT= BLUETOOTH

.if exists(/usr/lib/libcuse.so)
OPTIONS_DEFAULT+=	CUSE
.else
OPTIONS_EXCLUDE+=	CUSE
.endif

BLUETOOTH_DESC=	Build with bluetooth support
BLUETOOTH_MAKE_ARGS=	HAVE_BLUETOOTH="YES"

CUSE_DESC=	Use cuse(3) over multimedia/cuse4bsd-kmod
CUSE_MAKE_ARGS=		HAVE_CUSE="YES"
CUSE_SUB_LIST=		LIBCUSE=""
CUSE_BUILD_DEPENDS_OFF=	cuse4bsd-kmod>=0.1.24:multimedia/cuse4bsd-kmod
CUSE_LIB_DEPENDS_OFF=	libcuse4bsd.so:multimedia/cuse4bsd-kmod
CUSE_SUB_LIST_OFF=	LIBCUSE="${LOCALBASE}/lib/libcuse4bsd.so"

DEBUG_DESC=	Build with debugging support
DEBUG_MAKE_ARGS=	HAVE_DEBUG="YES"

PLIST_FILES=	sbin/virtual_oss \
		man/man8/virtual_oss.8.gz

MAKE_ARGS+=	PTHREAD_LIBS="-lpthread"

.include <bsd.port.mk>

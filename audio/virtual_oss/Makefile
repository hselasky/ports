# Created by: Hans Petter Selasky <hselasky@FreeBSD.org>
# $FreeBSD$

PORTNAME=	virtual_oss
PORTVERSION=	1.0.5
CATEGORIES=	audio
MASTER_SITES=	http://www.selasky.org/hans_petter/distfiles/ \
		http://home.selasky.org:8192/distfiles/

MAINTAINER=	hselasky@FreeBSD.org
COMMENT=	Virtual OSS multi device mixer application.

LICENSE=	BSD

BUILD_DEPENDS=	cuse4bsd-kmod>=0.1.24:${PORTSDIR}/multimedia/cuse4bsd-kmod

LIB_DEPENDS=	libcuse4bsd.so:${PORTSDIR}/multimedia/cuse4bsd-kmod \
		libsamplerate.so:${PORTSDIR}/audio/libsamplerate

USES=		tar:bzip2

PLIST_FILES=	sbin/virtual_oss

MAKE_ARGS+=" PTHREAD_LIBS=${PTHREAD_LIBS}"

.include <bsd.port.mk>

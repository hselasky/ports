# Created by: Hans Petter Selasky <hselasky@FreeBSD.org>
# $FreeBSD$

PORTNAME=	virtual_oss
PORTVERSION=	1.0.2
CATEGORIES=	audio
MASTER_SITES=	http://www.selasky.org/hans_petter/distfiles/ \
		http://home.selasky.org:8192/distfiles/

MAINTAINER=	hselasky@FreeBSD.org
COMMENT=	Virtual OSS multi device mixer application.

LICENSE=	BSD

BUILD_DEPENDS=	cuse4bsd-kmod>=0.1.24:${PORTSDIR}/multimedia/cuse4bsd-kmod

LIB_DEPENDS=	cuse4bsd.1:${PORTSDIR}/multimedia/cuse4bsd-kmod

USE_BZIP2=	yes
MAKE_JOBS_SAFE=	yes

PLIST_FILES=	sbin/virtual_oss

.include <bsd.port.options.mk>

MAKE_ARGS+=" PTHREAD_LIBS=${PTHREAD_LIBS}"

.include <bsd.port.mk>

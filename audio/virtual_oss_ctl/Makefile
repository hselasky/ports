# Created by: Hans Petter Selasky <hselasky@FreeBSD.org>
# $FreeBSD$

PORTNAME=	virtual_oss_ctl
PORTVERSION=	1.0.2
CATEGORIES=	audio
MASTER_SITES=	http://www.selasky.org/hans_petter/distfiles/ \
		http://hselasky.homeunix.org:8192/distfiles/

MAINTAINER=	hselasky@FreeBSD.org
COMMENT=	A grapical control panel for the virtual OSS daemon

LICENSE=	BSD
USE_BZIP2=	yes

USE_QT4=	gui qmake_build moc_build rcc_build

MAKE_JOBS_SAFE=	yes

QMAKE_VOSS=	${QMAKE} -unix PREFIX=${PREFIX} -o

.include <bsd.port.pre.mk>

do-configure:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${QMAKE_VOSS} Makefile ${PORTNAME}.pro

.include <bsd.port.post.mk>

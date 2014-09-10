# Created by: Andrew Thompson <thompsa@FreeBSD.org>
# $FreeBSD: head/multimedia/libv4l/Makefile 367444 2014-09-06 15:44:09Z nox $

PORTNAME=	libv4l
PORTVERSION=	1.4.0
CATEGORIES=	multimedia
MASTER_SITES=	http://linuxtv.org/downloads/v4l-utils/
DISTNAME=	v4l-utils-${PORTVERSION}

MAINTAINER=	hselasky@FreeBSD.org
COMMENT=	Video4Linux library

BUILD_DEPENDS=	v4l_compat>=1.0.20120501:${PORTSDIR}/multimedia/v4l_compat
LIB_DEPENDS=	libjpeg.so:${PORTSDIR}/graphics/jpeg \
		libargp.so:${PORTSDIR}/devel/argp-standalone

USES=		gmake libtool pathfix pkgconfig tar:bzip2
USE_LDCONFIG=	yes
USE_AUTOTOOLS=  aclocal autoconf autoheader automake libtoolize
AUTOMAKE_ARGS=  --add-missing

CONFIGURE_ENV= \
	CXX=${CXX} CC=${CC} \
	CFLAGS="-I${LOCALBASE}/include" \
	CXXFLAGS="-I${LOCALBASE}/include" \
	LDFLAGS="-L${LOCALBASE}/lib -largp"

CONFIGURE_ARGS= \
	--prefix="${PREFIX}" \
	--disable-libdvbv5 \
	--enable-libv4l \
	--disable-v4l-utils \
	--disable-qv4l2 \
	--without-jpeg

post-patch:
	@${RM} ${WRKSRC}/include/linux/videodev2.h

.include <bsd.port.mk>

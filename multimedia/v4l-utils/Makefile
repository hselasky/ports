# Created by: Juergen Lock <nox@FreeBSD.org>
# $FreeBSD: head/multimedia/v4l-utils/Makefile 361812 2014-07-14 18:42:04Z bapt $

PORTNAME=	v4l-utils
PORTVERSION=	1.4.0
CATEGORIES=	multimedia
MASTER_SITES=	http://linuxtv.org/downloads/v4l-utils/

MAINTAINER=	nox@FreeBSD.org
COMMENT=	Video4Linux utilities

BUILD_DEPENDS=	v4l_compat>=1.0.20120501:${PORTSDIR}/multimedia/v4l_compat \
		libv4l>=1.4.0:${PORTSDIR}/multimedia/libv4l
LIB_DEPENDS=	libv4l2.so:${PORTSDIR}/multimedia/libv4l \
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
	--enable-libdvbv5=no \
	--enable-libv4l=no \
	--enable-v4l-utils=yes \
	--enable-qv4l2=no \
	--without-jpeg

.include <bsd.port.options.mk>

.if ${OSVERSION} < 800000
EXTRA_PATCHES=	${FILESDIR}/extra-strnlen
.endif

post-patch:
	@${RM} ${WRKSRC}/include/linux/videodev2.h

.include <bsd.port.mk>


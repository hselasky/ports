# New ports collection makefile for:    mjpg-streamer
# Date created:                         24 April 2013
# Whom:                                 hselasky@freebsd.org
#
# $FreeBSD$
#
PORTNAME=	mjpg-streamer
PORTVERSION=	r63
CATEGORIES=	multimedia
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/Sourcecode

MAINTAINER=	hselasky@freebsd.org
COMMENT=	A Video4Linux webcam HTTP MPEG streamer

BUILD_DEPENDS=	${LOCALBASE}/include/linux/videodev.h:${PORTSDIR}/multimedia/v4l_compat
LIB_DEPENDS=	jpeg.11:${PORTSDIR}/graphics/jpeg

USE_LDCONFIG=	yes
USE_GMAKE=	yes

GMAKE_ARGS+= CC=${CC} PTHREAD_LIBS=${PTHREAD_LIBS} LOCALBASE=${LOCALBASE}

PLIST_FILES= \
	bin/mjpg_streamer \
	lib/mjpg_streamer/input_gspcav1.so \
	lib/mjpg_streamer/input_testpicture.so \
	lib/mjpg_streamer/input_uvc.so \
	lib/mjpg_streamer/output_autofocus.so \
	lib/mjpg_streamer/output_file.so \
	lib/mjpg_streamer/output_http.so

do-build:
	cd ${WRKSRC}/plugins/input_gspcav1 && ${GMAKE} ${GMAKE_ARGS}
	cd ${WRKSRC}/plugins/input_testpicture && ${GMAKE} ${GMAKE_ARGS}
	cd ${WRKSRC}/plugins/input_uvc && ${GMAKE} ${GMAKE_ARGS}
	cd ${WRKSRC}/plugins/output_autofocus && ${GMAKE} ${GMAKE_ARGS}
	cd ${WRKSRC}/plugins/output_file && ${GMAKE} ${GMAKE_ARGS}
	cd ${WRKSRC}/plugins/output_http && ${GMAKE} ${GMAKE_ARGS}
	cd ${WRKSRC} && ${GMAKE} ${GMAKE_ARGS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mjpg_streamer ${PREFIX}/bin
	${MKDIR} ${PREFIX}/lib/mjpg_streamer
	${INSTALL_LIB} ${WRKSRC}/input_gspcav1.so ${PREFIX}/lib/mjpg_streamer/input_gspcav1.so
	${INSTALL_LIB} ${WRKSRC}/input_testpicture.so ${PREFIX}/lib/mjpg_streamer/input_testpicture.so
	${INSTALL_LIB} ${WRKSRC}/input_uvc.so ${PREFIX}/lib/mjpg_streamer/input_uvc.so
	${INSTALL_LIB} ${WRKSRC}/output_autofocus.so ${PREFIX}/lib/mjpg_streamer/output_autofocus.so
	${INSTALL_LIB} ${WRKSRC}/output_file.so ${PREFIX}/lib/mjpg_streamer/output_file.so
	${INSTALL_LIB} ${WRKSRC}/output_http.so ${PREFIX}/lib/mjpg_streamer/output_http.so

.include <bsd.port.mk>

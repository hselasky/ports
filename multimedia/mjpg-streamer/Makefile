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
LIB_DEPENDS=	libjpeg.11:${PORTSDIR}/graphics/jpeg

USE_LDCONFIG=	yes
USE_GMAKE=	yes

GMAKE_ARGS+= CC=${CC} PTHREAD_LIBS=${PTHREAD_LIBS} LOCALBASE=${LOCALBASE}

PLIST_FILES= \
	bin/mjpg_streamer \
	share/mjpg_streamer/plugins/input_gspcav1.so \
	share/mjpg_streamer/plugins/input_testpicture.so \
	share/mjpg_streamer/plugins/input_uvc.so \
	share/mjpg_streamer/plugins/output_autofocus.so \
	share/mjpg_streamer/plugins/output_file.so \
	share/mjpg_streamer/plugins/output_http.so\
	share/mjpg_streamer/www/LICENSE.txt \
	share/mjpg_streamer/www/bodybg.gif \
	share/mjpg_streamer/www/cambozola.jar \
	share/mjpg_streamer/www/control.htm \
	share/mjpg_streamer/www/example.jpg \
	share/mjpg_streamer/www/favicon.ico \
	share/mjpg_streamer/www/favicon.png \
	share/mjpg_streamer/www/fix.css \
	share/mjpg_streamer/www/functions.js \
	share/mjpg_streamer/www/index.html \
	share/mjpg_streamer/www/java.html \
	share/mjpg_streamer/www/java_control.html \
	share/mjpg_streamer/www/java_simple.html \
	share/mjpg_streamer/www/javascript.html \
	share/mjpg_streamer/www/javascript_simple.html \
	share/mjpg_streamer/www/sidebarbg.gif \
	share/mjpg_streamer/www/static.html \
	share/mjpg_streamer/www/static_simple.html \
	share/mjpg_streamer/www/stream.html \
	share/mjpg_streamer/www/stream_simple.html \
	share/mjpg_streamer/www/style.css

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
	${MKDIR} ${PREFIX}/share/mjpg_streamer
	${MKDIR} ${PREFIX}/share/mjpg_streamer/www
	${MKDIR} ${PREFIX}/share/mjpg_streamer/plugins
	${INSTALL_LIB} ${WRKSRC}/input_gspcav1.so ${PREFIX}/share/mjpg_streamer/plugins/input_gspcav1.so
	${INSTALL_LIB} ${WRKSRC}/input_testpicture.so ${PREFIX}/share/mjpg_streamer/plugins/input_testpicture.so
	${INSTALL_LIB} ${WRKSRC}/input_uvc.so ${PREFIX}/share/mjpg_streamer/plugins/input_uvc.so
	${INSTALL_LIB} ${WRKSRC}/output_autofocus.so ${PREFIX}/share/mjpg_streamer/plugins/output_autofocus.so
	${INSTALL_LIB} ${WRKSRC}/output_file.so ${PREFIX}/share/mjpg_streamer/plugins/output_file.so
	${INSTALL_LIB} ${WRKSRC}/output_http.so ${PREFIX}/share/mjpg_streamer/plugins/output_http.so
	${INSTALL_DATA} ${WRKSRC}/www/LICENSE.txt ${PREFIX}/share/mjpg_streamer/www/LICENSE.txt
	${INSTALL_DATA} ${WRKSRC}/www/bodybg.gif ${PREFIX}/share/mjpg_streamer/www/bodybg.gif
	${INSTALL_DATA} ${WRKSRC}/www/cambozola.jar ${PREFIX}/share/mjpg_streamer/www/cambozola.jar
	${INSTALL_DATA} ${WRKSRC}/www/control.htm ${PREFIX}/share/mjpg_streamer/www/control.htm
	${INSTALL_DATA} ${WRKSRC}/www/example.jpg ${PREFIX}/share/mjpg_streamer/www/example.jpg
	${INSTALL_DATA} ${WRKSRC}/www/favicon.ico ${PREFIX}/share/mjpg_streamer/www/favicon.ico
	${INSTALL_DATA} ${WRKSRC}/www/favicon.png ${PREFIX}/share/mjpg_streamer/www/favicon.png
	${INSTALL_DATA} ${WRKSRC}/www/fix.css ${PREFIX}/share/mjpg_streamer/www/fix.css
	${INSTALL_DATA} ${WRKSRC}/www/functions.js ${PREFIX}/share/mjpg_streamer/www/functions.js
	${INSTALL_DATA} ${WRKSRC}/www/index.html ${PREFIX}/share/mjpg_streamer/www/index.html
	${INSTALL_DATA} ${WRKSRC}/www/java.html ${PREFIX}/share/mjpg_streamer/www/java.html
	${INSTALL_DATA} ${WRKSRC}/www/java_control.html ${PREFIX}/share/mjpg_streamer/www/java_control.html
	${INSTALL_DATA} ${WRKSRC}/www/java_simple.html ${PREFIX}/share/mjpg_streamer/www/java_simple.html
	${INSTALL_DATA} ${WRKSRC}/www/javascript.html ${PREFIX}/share/mjpg_streamer/www/javascript.html
	${INSTALL_DATA} ${WRKSRC}/www/javascript_simple.html ${PREFIX}/share/mjpg_streamer/www/javascript_simple.html
	${INSTALL_DATA} ${WRKSRC}/www/sidebarbg.gif ${PREFIX}/share/mjpg_streamer/www/sidebarbg.gif
	${INSTALL_DATA} ${WRKSRC}/www/static.html ${PREFIX}/share/mjpg_streamer/www/static.html
	${INSTALL_DATA} ${WRKSRC}/www/static_simple.html ${PREFIX}/share/mjpg_streamer/www/static_simple.html
	${INSTALL_DATA} ${WRKSRC}/www/stream.html ${PREFIX}/share/mjpg_streamer/www/stream.html
	${INSTALL_DATA} ${WRKSRC}/www/stream_simple.html ${PREFIX}/share/mjpg_streamer/www/stream_simple.html
	${INSTALL_DATA} ${WRKSRC}/www/style.css ${PREFIX}/share/mjpg_streamer/www/style.css

.include <bsd.port.mk>

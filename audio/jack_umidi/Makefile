# Created by: Hans Petter Selasky <hselasky@FreeBSD.org>
# $FreeBSD$

PORTNAME=	jack_umidi
PORTVERSION=	1.0.9
CATEGORIES=	audio
MASTER_SITES=	http://www.selasky.org/hans_petter/distfiles/ \
		http://home.selasky.org:8192/distfiles/

MAINTAINER=	hselasky@FreeBSD.org
COMMENT=	Daemon that converts a raw MIDI device into a JACK MIDI device

LICENSE=	BSD2CLAUSE

LIB_DEPENDS=	libjack.so:${PORTSDIR}/audio/jack

USES=		tar:bzip2 uidfix
PLIST_FILES=	sbin/jack_umidi \
		man/man8/jack_umidi.8.gz

OPTIONS_DEFINE=        DEBUG DEVD_SCRIPT

DEVD_SCRIPT_DESC=	Install devd script to auto-launch jack_umidi

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDEVD_SCRIPT}
PLIST_FILES+=	etc/devd/jack_umidi.conf
.endif

MAKE_ARGS+=" HAVE_MAN=YES"
MAKE_ARGS+=" PTHREAD_LIBS=${PTHREAD_LIBS}"

.if ${PORT_OPTIONS:MDEBUG}
MAKE_ARGS+=" HAVE_DEBUG=YES"
.endif

.include <bsd.port.pre.mk>

post-install:
.if ${PORT_OPTIONS:MDEVD_SCRIPT}
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/devd
	@${SED} -e "s|%%PREFIX%%|${PREFIX}|g" \
	    < ${FILESDIR}/jack_umidi.conf.in > ${WRKDIR}/jack_umidi.conf
	${INSTALL_DATA} "${WRKDIR}/jack_umidi.conf" ${STAGEDIR}${PREFIX}/etc/devd
.endif

.include <bsd.port.post.mk>

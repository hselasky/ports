# Ports collection makefile for: jack_umidi
# Date created: 21 June 2011
# Whom:         Hans Petter Selasky <hselasky@FreeBSD.org>
#
# $FreeBSD: ports/audio/jack_umidi/Makefile,v 1.1 2011/06/23 12:53:24 kwm Exp $
#

PORTNAME=	jack_umidi
PORTVERSION=	1.0.0
CATEGORIES=	audio
MASTER_SITES=	http://www.selasky.org/hans_petter/distfiles/ \
		http://hselasky.homeunix.org:8192/distfiles/

MAINTAINER=	hselasky@FreeBSD.org
COMMENT=	A daemon that converts a raw MIDI device into a JACK MIDI device.

LIB_DEPENDS=	jack.0:${PORTSDIR}/audio/jack

LICENSE=	BSD
USE_BZIP2=	yes
MAKE_JOBS_SAFE=	yes
MANCOMPRESSED=	yes
MAN8=		jack_umidi.8

PLIST_FILES=	sbin/jack_umidi

OPTIONS=	DEBUG "Build with debugging support" Off

.include <bsd.port.options.mk>

MAKE_ARGS+=" HAVE_MAN=YES"

.if defined(WITH_DEBUG)
MAKE_ARGS+=" HAVE_DEBUG=YES"
.endif

.include <bsd.port.mk>

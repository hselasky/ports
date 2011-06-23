# Ports collection makefile for: libumidi
# Date created: 21 June 2011
# Whom:         Hans Petter Selasky <hselasky@FreeBSD.org>
#
# $FreeBSD: ports/audio/libumidi/Makefile,v 1.1 2011/06/23 12:54:14 kwm Exp $
#

PORTNAME=	libumidi
PORTVERSION=	2.0.0
CATEGORIES=	audio
MASTER_SITES=	http://www.selasky.org/hans_petter/distfiles/ \
		http://hselasky.homeunix.org:8192/distfiles/

MAINTAINER=	hselasky@FreeBSD.org
COMMENT=	A universal general purpose MIDI library

LICENSE=	BSD
USE_BZIP2=	yes
MAN3=		umidi20.3
MANCOMPRESSED=	yes

OPTIONS=	DEBUG "Build with debugging support" Off \
		JACK "Build with Jack support" On

.include <bsd.port.options.mk>

.if defined(WITH_JACK)
MAKE_ARGS+=" HAVE_JACK=YES"
LIB_DEPENDS=	jack.0:${PORTSDIR}/audio/jack
.endif

.if defined(WITH_DEBUG)
MAKE_ARGS+=" HAVE_DEBUG=YES"
.endif

MAKE_ARGS+=" HAVE_MAN=YES"

.include <bsd.port.mk>

# New ports collection makefile for:	jack-keyboard
# Date created:		2007-01-23
# Whom:			trasz <trasz@pin.if.uz.zgora.pl>
#
# $FreeBSD: ports/audio/jack-keyboard/Makefile,v 1.22 2010/03/28 06:31:06 dinoex Exp $
#

PORTNAME=	jack-keyboard
DISTVERSION=	2.5
PORTREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	SF

MAINTAINER=	trasz@FreeBSD.org
COMMENT=	Virtual keyboard for JACK MIDI

LIB_DEPENDS=	jack.0:${PORTSDIR}/audio/jack \
		lash.2:${PORTSDIR}/audio/lash

MAN1=		jack-keyboard.1

GNU_CONFIGURE=	yes
USE_GNOME=	gtk20
INSTALLS_ICONS=	yes

.include <bsd.port.mk>

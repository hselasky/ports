# Created by: Konstantin Reznichenko <kot@premierbank.dp.ua>
# $FreeBSD: head/archivers/arj/Makefile 371241 2014-10-20 08:12:20Z marino $

PORTNAME=	dymo-cups-drivers
PORTVERSION=	1.4.0
PORTREVISION=	4
CATEGORIES=	archivers
MASTER_SITES=	http://download.dymo.com/Software/Linux/
WRKSRC=		work/dymo-cups-drivers-1.4.0.5
MAINTAINER=	hselasky@FreeBSD.org
COMMENT=	Open source DYMO CUPS driver
CONFIGURE_ENV=	CFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib"
LICENSE=	GPLv2

USES=		gmake
USE_AUTOTOOLS=	autoconf
ALL_TARGET=	all
STRIP=		# empty

.include <bsd.port.mk>

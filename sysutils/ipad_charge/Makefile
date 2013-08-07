# New ports collection makefile for:	ipad_charge
# Date created:		13 January 2012
# Whom:			Kevin Lo <kevlo@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ipad_charge
PORTVERSION=	2.0.1
CATEGORIES=	sysutils
DISTFILES=

MAINTAINER=	kevlo@FreeBSD.org
COMMENT=	A generic iPad USB charging utility

LICENSE=	BSD

USE_RC_SUBR=	ipad_charge

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800000
IGNORE=		requires FreeBSD 8.0-RELEASE or later
.endif

do-build:

do-install:

post-install:
	@${MKDIR} ${PREFIX}/etc/devd
	@${SED} -e "s|%%PREFIX%%|${PREFIX}|g" \
		< ${FILESDIR}/ipad_charge.conf.in > ${WRKDIR}/ipad_charge.conf
	${INSTALL_DATA} "${WRKDIR}/ipad_charge.conf" ${PREFIX}/etc/devd
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>

# Created by: Stanislav Putrya <vagner@bsdway.ru>
# $FreeBSD: head/security/php-pssh/Makefile 2013-10-13 16:23:20Z vagner $
#
PORTNAME=       pssh
PORTVERSION=    1.4.1
CATEGORIES=    	security 
PKGNAMEPREFIX=  php-

MAINTAINER=     vagner@bsdway.ru        
COMMENT=        Badoo\'s open source php extention for asynchronous ssh lib

LICENSE=        BSD

USE_GITHUB=     yes
NO_STAGE=       yes
GH_ACCOUNT=     svagner
GH_PROJECT=     ${PORTNAME}
GH_COMMIT=      00b1ac4

LIB_DEPENDS=    pssh:${PORTSDIR}/security/libpssh

DIST_SUBDIR=    PECL

USE_PHP=        yes
USE_PHPEXT=     yes

.include <bsd.port.mk>


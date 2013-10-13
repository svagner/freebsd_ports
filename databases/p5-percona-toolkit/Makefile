# New ports collection makefile for:	p5-percona-toolkit
# Date created:		2012-08-20
# Whom:			Stanislav Putrya <vagner@bsdway.ru>
#
# $FreeBSD$
#

PORTNAME=	percona-toolkit	
PORTVERSION=	2.1.3
CATEGORIES=	databases perl5
MASTER_SITES=	http://www.percona.com/redir/downloads/percona-toolkit/LATEST/ \
		http://www.bsdway.ru/downloads/databases/Percona-Toolkit-2.1/Percona-Toolkit-2.1.3/source/
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:C/0$//}

MAINTAINER=	vagner@bsdway.ru
COMMENT=	Command-line tools used by Percona support for MySQL 5.1

BUILD_DEPENDS=	p5-DBD-mysql51>=0:${PORTSDIR}/databases/p5-DBD-mysql51

CFLAGS+=	-I${BDB_INCLUDE_DIR}
LDFLAGS+=	${PTHREAD_LIBS}
PERL_CONFIGURE=	yes


.include <bsd.port.mk>

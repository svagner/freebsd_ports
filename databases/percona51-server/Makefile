# New ports collection makefile for:	xtradb
# Date created:				29 Marc 2012
# Whom:					Stanislav Putrya <vagner@bsdway.ru>
#
# $FreeBSD$
#

PORTNAME=	Percona-Server
PORTVERSION=	5.1.61
CATEGORIES=	databases
MASTER_SITES=	http://www.percona.com/downloads/Percona-Server-5.1/Percona-Server-5.1.61-13.2/source/ \
		http://www.bsdway.ru/downloads/databases/Percona-Server-5.1/Percona-Server-5.1.61-13.2/source/

MAINTAINER=	vagner@bsdway.ru
COMMENT=	OpenSource version Percona Server MySQL with XtraDB Version ${PORTVERSION}

BUILD_DEPENDS=	bison:${PORTSDIR}/devel/bison/ \
		perl:${PORTSDIR}/lang/perl5.12/
RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/DBD/mysql.pm:${PORTSDIR}/databases/p5-DBD-mysql51
SLAVEDIRS=	databases/mysql51-client databases/mysql51-scripts
GNU_CONFIGURE=	yes
MAKE_JOBS_SAFE=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool
USERS=		mysql
GROUPS=		mysql

CONFIGURE_ARGS=	--with-comment="${PORTNAME}-${PORTVERSION} ${COMMENT}" \
		--localstatedir=/var/db/mysql

.if !defined(WITHOUT_XTRADB_OPTIONS)
.include "${.CURDIR}/Makefile.options"
.include <bsd.port.options.mk>
.endif

.if defined(WITHOUT_STATICLIB)
CONFIGURE_ARGS+=	--enable-static=no
.else
CONFIGURE_ARGS+=	--enable-static
.endif

.if defined(WITHOUT_SHAREDLIB)
CONFIGURE_ARGS+=	--enable-shared=no
.else
CONFIGURE_ARGS+=	--enable-shared
.endif

.if defined(WITH_LOAD_INFILE)
CONFIGURE_ARGS+=	--enable-local-infile
.endif

.if defined(WITH_CP1251_CHARSET)
CONFIGURE_ARGS+=	--with-charset=cp1251
.endif

.if defined(WITH_INNOBASE_PLUGIN)
CONFIGURE_ARGS+=	--with-plugin-innobase
.else
CONFIGURE_ARGS+=	--without-plugin-innobase
.endif

.if defined(WITHOUT_INNODB_PLUGIN)
CONFIGURE_ARGS+=	--without-plugin-innodb_plugin
.else
CONFIGURE_ARGS+=	--with-plugin-innodb_plugin
.endif

.if defined(WITH_PARTITION_PLUGIN)
CONFIGURE_ARGS+=	--with-plugin-partition
.else
CONFIGURE_ARGS+=	--without-plugin-partition
.endif

.if defined(WITHOUT_ARCHIVE_PLUGIN)
CONFIGURE_ARGS+=	--without-plugin-archive
.else
CONFIGURE_ARGS+=	--with-plugin-archive
.endif

.if defined(WITHOUT_BLACKHOLE)
CONFIGURE_ARGS+=	--without-plugin-blackhole
.else
CONFIGURE_ARGS+=	--with-plugin-blackhole
.endif

.if defined(WITH_NDBCLUSTER)
CONFIGURE_ARGS+=	--with-plugin-ndbcluster
.else
CONFIGURE_ARGS+=	--without-plugin-ndbcluster
.endif

.if defined(WITHOUT_DOCS)
CONFIGURE_ARGS+=	--without-dosc
.endif

.if defined(WITHOUT_MANPAGES)
CONFIGURE_ARGS+=	--without-man
.endif

post-install:
.if !defined(PACKAGE_BUILDING)
	@${CAT} ${PKGMESSAGE}
	@${CP} ${FILESDIR}/mysql-server ${LOCALBASE}/etc/rc.d/
	@${CP} ${FILESDIR}/my-medium.cnf ${LOCALBASE}/etc/my.cnf
	@${SH} ${PREFIX}/bin/mysql_install_db
.endif

.include <bsd.port.mk>

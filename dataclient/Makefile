NAMES	=	server
NAMEC	=	client

SRCS	=	dserver/main.c\
		dserver/set_path.c\
		dserver/manage_cmd.c\
		dserver/connection.c\
		dserver/get_message.c\
		dserver/init.c\
		dserver/my_cd.c\
		dserver/my_pwd.c\
		dserver/my_ls.c\
		dserver/my_put.c\
		dserver/my_get.c\
		dserver/get_passwd_file.c\
		func/my_totab.c

SRCC	=	dclient/main.c

OBJS	=	$(SRCS:.c=.o)
OBJC	=	$(SRCC:.c=.o)

CFLAGS	=	-g

all:		$(NAMES) $(NAMEC)

$(NAMES):	$(OBJS) $(OBJC)
		cc -o $(NAMES) $(OBJS) -lpthread
		cc -o $(NAMEC) $(OBJC)

clean:
	rm -f $(OBJS) $(OBJC)

fclean:	clean
	rm -f $(NAMES) $(NAMEC)

re:	fclean all

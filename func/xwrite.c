int	xwrite(int fd, char buff[1024], int size)
{
  if (write(fd, buff, size) == -1)
    return (-1);
  return (0);
}

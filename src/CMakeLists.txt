ADD_EXECUTABLE( pelayan
  main.c
  filetype.c
  intern/help.c
  intern/settings.c
  intern/gzip.c
  socket/server.c
  socket/client.c
  socket/send.c
  http/buffer.c
  http/request.c
  http/response.c
  misc/tokenizer.c
  misc/mstring.c
  misc/dstring.c
)

require 'dll'
LIB=:'c:/users/joe/downloads/libuv/libuv_shim.dll '
add=:(LIB,'add >+ x x x')&cd
timer_create_default=:(LIB,'timer_create_default >+ x')&cd
timer_start=:(LIB,'timer_start + n x')&cd
timer_start_cb=:(LIB,'timer_start_cb + n x x')&cd


cdcb1=: cdcb 1

cdcallback =: 3 : 0
smoutput y
smoutput 'yo'
)

go=: 3 : 0
smoutput add (1;2)
timer=:timer_create_default''
smoutput timer
NB. timer_start timer
timer_start_cb (timer;cdcb1)
smoutput 'here'
cdf''
)
NB. go''
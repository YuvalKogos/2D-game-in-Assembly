.data
;;;;;;;;;;;;;;;;;;;;;images draw;;;;;;;;;;;;;;;;


filename1 byte "ground1.bmp",0
	
ground Img<>

filename2 byte "gravityplayer.bmp",0
	
playerI Img<>

filename3 byte "enemy1.bmp",0
	
enemy1I Img<>

filename4 byte "shot1.bmp",0
	
shot1 Img<>

filename5 byte "floor1.bmp",0
	
floor1 Img<>

filename6 byte "life1.bmp",0
	
life Img<>

filename7 byte "lifel.bmp",0
	
lifelabel Img<>

filename8 byte "num0.bmp",0
	
num0 Img<>

filename9 byte "num1.bmp",0
	
num1 Img<>

filename10 byte "num2.bmp",0
	
num2 Img<>

filename11 byte "num3.bmp",0
	
num3 Img<>

filename12 byte "num4.bmp",0
	
num4 Img<>

filename13 byte "num5.bmp",0
	
num5 Img<>

filename14 byte "num6.bmp",0
	
num6 Img<>

filename15 byte "num7.bmp",0
	
num7 Img<>

filename16 byte "num8.bmp",0
	
num8 Img<>

filename17 byte "num9.bmp",0
	
num9 Img<>

filename18 byte "time.bmp",0
	
time Img<>

filename19 byte "background.bmp",0
	
background Img<>


filename20 byte "start.bmp",0
	
start Img<>



;;;;;;;;;;;structs;;;;;;;;;;;;;


Shoot struct
	x DWORD ?
	y DWORD ?
	reset_shoot DWORD ?
Shoot ends

Player struct
	x DWORD 50
	y DWORD 315
	up DWORD 0
	down DWORD 0
Player ends

EnemyD struct
	x DWORD ?
	y DWORD ?
	up DWORD 1 
	down DWORD 0
EnemyD ends

EnemyS struct
	x DWORD ?
	y DWORD ?
	left DWORD 0
	right DWORD 1
EnemyS ends


AIP struct
	x DWORD 300
	y DWORD 380
	

AIP ends

;;;;;;;structs declerations;;;;;;;;;;;;;

aip AIP <300,380>

enemy1 EnemyD <20,250>

enemy2 EnemyD <675,300>

enemy3 EnemyS <300,5>

shot1s Shoot <5,10,1>

shot2s Shoot <750,10,1>

shot3s Shoot <5,40,1>

AiShoot Shoot <3,5,1>

player Player <>


;;for loop variables;;

i DWORD 10
d DWORD 10
f DWORD 10
q DWORD 10
t DWORD 10
k DWORD 10
b DWORD 2500
l DWORD 10
n DWORD 10
j DWORD 10
ki DWORD 10

;;;;;;;;;;;;;general varielbes;;;;;;;;;;;

shootingLoopSpeed DWORD 3000

shoot1 DWORD 0
shoot2 DWORD 0
shoot3 DWORD 0

playerLife DWORD 3
fallSpeed DWORD 1

startGame DWORD 0
pauseGame DWORD 1

score DWORD 50

flag DWORD 0

aiLeft DWORD 0
aiRight DWORD 0
velocy DWORD 0

aiAbleToUp DWORD 1

aiAbleToDown DWORD 1


shootAi DWORD 1
include \masm32\include\masm32rt.inc


.code

loadImages proc
invoke drd_imageLoadFile,offset filename1,offset ground
invoke drd_imageLoadFile,offset filename2,offset playerI
invoke drd_imageLoadFile,offset filename3,offset enemy1I
invoke drd_imageLoadFile,offset filename4,offset shot1
invoke drd_imageLoadFile,offset filename5,offset floor1
invoke drd_imageLoadFile,offset filename6,offset life
invoke drd_imageLoadFile,offset filename7,offset lifelabel
invoke drd_imageLoadFile,offset filename8,offset num0
invoke drd_imageLoadFile,offset filename9,offset num1
invoke drd_imageLoadFile,offset filename10,offset num2
invoke drd_imageLoadFile,offset filename11,offset num3
invoke drd_imageLoadFile,offset filename12,offset num4
invoke drd_imageLoadFile,offset filename13,offset num5
invoke drd_imageLoadFile,offset filename14,offset num6
invoke drd_imageLoadFile,offset filename15,offset num7
invoke drd_imageLoadFile,offset filename16,offset num8
invoke drd_imageLoadFile,offset filename17,offset num9
invoke drd_imageLoadFile,offset filename18,offset time
invoke drd_imageLoadFile,offset filename19,offset background
invoke drd_imageLoadFile,offset filename20,offset start


ret
loadImages endp




;;;;;;;;;;;;;collision func;;;;;;;;;;;;;;;;;;



detect_collision PROC, firstx: DWORD, firsty: DWORD, firstwidth: DWORD, firstheight: DWORD, secondx: DWORD, secondy: DWORD, secondwidth: DWORD, secondheight: DWORD




mov eax, firstx
add eax, firstwidth 
cmp eax, secondx
jl no_collision

mov eax, secondx
add eax, secondwidth 
cmp eax, firstx
jl no_collision

mov eax, firsty
add eax, firstheight 
cmp eax, secondy
jl no_collision

mov eax, secondy
add eax, secondheight 
cmp eax, firsty
jl no_collision

mov flag, 1

ret

no_collision: mov flag, 0

ret

detect_collision endp


;;;;;;;;;;;;;;;;;;keyboard recognision;;;;;;;;;;;;;;;;;

key_handler PROC, keyCode:DWORD

	cmp keyCode,37
	je moveLeft

	cmp keyCode,39
	je moveRight

	cmp keyCode,38
	je upline

	cmp keyCode,13
	je StartGameLine

	ret

	moveLeft:
	sub player.x,12

	ret
	
	moveRight: 
	add player.x,12

	ret

	StartGameLine:
	mov pauseGame,0
	mov enemy3.x,300
	mov startGame,1

	ret

	upline:
	mov player.up,1
	mov player.down,0
	
	ret

	ret
key_handler endp



pauseGameFunc proc
invoke drd_imageDraw,offset start, 0, 0
		mov n,100000
		mov shot1s.x,100000
		mov shot2s.x,100000
		mov shot3s.x,100000
		mov enemy1.x,2000
		mov enemy2.x,2000
		mov enemy3.x,2000
		
		mov enemy2.up,0
		mov enemy2.down,0
		;mov enemy3_left,0
		;mov enemy3_right,0
		mov shot1s.reset_shoot,1
		mov shot2s.reset_shoot,1
		mov shot3s.reset_shoot,1

ret
pauseGameFunc endp


startGameFunc proc
mov n,10
			mov shot1s.x,5
			mov shot2s.x,250
			mov shot3s.x,5
			mov enemy1.x,20
			mov enemy2.x,675
			mov playerLife,3
			mov enemy3.right,1
			;mov playerLife,3
			mov score,50
			mov startGame,0

ret
startGameFunc endp

drawLife proc

invoke drd_imageDraw,offset lifelabel, 100, 440

cmp playerLife,3
	jne AFterDrawingLife
	invoke drd_imageDraw,offset life, 170, 450
	invoke drd_imageDraw,offset life, 200, 450
	invoke drd_imageDraw,offset life, 230, 450
	AFterDrawingLife:

	cmp playerLife,2
	jne AFterDrawingLife2
	invoke drd_imageDraw,offset life, 170, 450
	invoke drd_imageDraw,offset life, 200, 450
	AFterDrawingLife2:

	cmp playerLife,1
	jne AFterDrawingLife1
	invoke drd_imageDraw,offset life, 170, 450
	AFterDrawingLife1:


ret
drawLife endp


enemy_movment proc enemy: DWORD 

cmp enemy,3
jne afterInEnemyFunction1

 invoke drd_imageDraw,offset enemy1I, enemy3.x, enemy3.y

	mov eax,player.x

	cmp enemy3.x,eax
	jle thedickofchosenandtheballshairofsofer1
	mov enemy3.right,0
	mov enemy3.left,1
	thedickofchosenandtheballshairofsofer1:

	cmp enemy3.x,eax
	jge afterEnemy2ChangeDirection78
	mov enemy3.left,0
	mov enemy3.right,1
	afterEnemy2ChangeDirection78:

	cmp enemy3.left,1
	jne afterEnemy3MoveLeft
		cmp l,17
		jne afterInEnemy3LeftStatement
		dec enemy3.x
		mov l,10
		afterInEnemy3LeftStatement:
		inc l
	afterEnemy3MoveLeft:

	cmp enemy3.right,1
	jne afterEnemy3MoveLeft1
		cmp l,17
		jne afterInEnemy3LeftStatement1
		inc enemy3.x
		mov l,10
		afterInEnemy3LeftStatement1:
		inc l
	afterEnemy3MoveLeft1:


afterInEnemyFunction1:


cmp enemy,2
jne afterInEnemyFunction2
invoke drd_imageDraw,offset enemy1I, enemy2.x, enemy2.y


	

	mov eax,player.y

	cmp enemy2.y,eax
	jle thedickofchosenandtheballshairofsofer
	mov enemy2.up,1
	mov enemy2.down,0
	thedickofchosenandtheballshairofsofer:

	cmp enemy2.y,eax
	jge afterEnemy2ChangeDirection9
	mov enemy2.down,1
	mov enemy2.up,0
	afterEnemy2ChangeDirection9:

	cmp enemy2.up,1
	jne afterEnemy2Up
		cmp k,17
		jne InEnemy2Statement1
		dec enemy2.y
		mov k,10

		InEnemy2Statement1:
		inc k
	afterEnemy2Up:

	cmp enemy2.down,1
	jne afterenemy2down
		cmp k,17
		jne inenemy2statement2
		inc enemy2.y
		mov k,10
		inenemy2statement2:
		inc k
	afterenemy2down:

	
	cmp enemy2.y,270
	jne afterChangeDirectionenemy2withscreen
	mov enemy2.down,0
	afterChangeDirectionenemy2withscreen:

	cmp enemy2.y,0
	jne AfterChangedirecitionEnemy2
	mov enemy2.up,0
	AfterChangedirecitionEnemy2:


afterInEnemyFunction2:


cmp enemy,1
jne adterInEnemyFunction3
invoke drd_imageDraw,offset enemy1I, enemy1.x, enemy1.y
		
		cmp enemy1.up,1
		jne afterEnemyMoveUp
			
			cmp f,17
			jne inEnemyMoveUpLoop
			dec enemy1.y
			mov f,10
			inEnemyMoveUpLoop:
			inc f
		afterEnemyMoveUp:
		


		cmp enemy1.down,1
		jne afterEnemyDown
			cmp f,17
			jne inEnemyMoveDownLoop
			inc enemy1.y
			mov f,10

			inEnemyMoveDownLoop:
			inc f
		afterEnemyDown:

		cmp enemy1.y,1
		jg AfterCollisionOfEnemyWithTopOfScreen
		mov enemy1.up,0
		mov enemy1.down,1
		AfterCollisionOfEnemyWithTopOfScreen:
		
		cmp enemy1.y, 270
		jl AfterCollisionOfEnemyWithBottonOFScreen
		mov enemy1.down,0
		mov enemy1.up,1
		AfterCollisionOfEnemyWithBottonOFScreen:

adterInEnemyFunction3:

ret
enemy_movment endp


 enemy3Movement proc

 ret
enemy3Movement endp



enemy2Movement proc


ret
enemy2Movement endp


gravity proc 

cmp player.down,1
		jne afterDownStatement
					cmp q,15
					jne afterQStatementInGravity				
					inc player.y
					mov q,10
					afterQStatementInGravity:
					inc q
			cmp player.y,315
			jne inDownStatement
			mov player.down,0
			
			inDownStatement:
		afterDownStatement:

ret
gravity endp


jump proc

cmp player.up,1
		jne afterUpStatement
		dec player.y
		inc i
			cmp i,150
			jne inUpStatement
			mov player.up,0
			mov player.down,1
			mov i,10
			inUpStatement:
		afterUpStatement:

ret
jump endp


scoreFunc proc
cmp n,500
		jne AfterScoreLoop
		dec score
		mov n,10
		AfterScoreLoop:
		inc n
	

;	mov ebx,score

	;mov eax, ebx mod 10

	mov edx, 0     
	mov eax, score
	mov bx, 10
	div bx    

	;;ones






	.if edx == 0
	invoke drd_imageDraw,offset num0, 650, 440
	.endif

	.if edx == 1
	invoke drd_imageDraw,offset num1, 650, 440
	.endif

	.if edx == 2
	invoke drd_imageDraw,offset num2, 650, 440
	.endif

	.if edx == 3
	invoke drd_imageDraw,offset num3, 650, 440
	.endif

	.if edx == 4
	invoke drd_imageDraw,offset num4, 650, 440
	.endif

	.if edx == 5
	invoke drd_imageDraw,offset num5, 650, 440
	.endif

	.if edx == 6
	invoke drd_imageDraw,offset num6, 650, 440
	.endif

	.if edx == 7
	invoke drd_imageDraw,offset num7, 650, 440
	.endif

	.if edx == 8
	invoke drd_imageDraw,offset num8, 650, 440
	.endif

	.if edx == 9
	invoke drd_imageDraw,offset num9, 650, 440
	.endif

	;;tens

	
	mov edx, 0     
	mov eax, score
	mov bx, 10
	div bx    

	

	.if eax == 1
	invoke drd_imageDraw,offset num1, 620, 440
	.endif
	
	.if eax == 2
	invoke drd_imageDraw,offset num2, 620, 440
	.endif

	.if eax == 3
	invoke drd_imageDraw,offset num3, 620, 440
	.endif

	.if eax == 4
	invoke drd_imageDraw,offset num4, 620, 440
	.endif

	.if eax == 5
	invoke drd_imageDraw,offset num5, 620, 440
	.endif

	.if eax == 6
	invoke drd_imageDraw,offset num6, 620, 440
	.endif

	.if eax == 7
	invoke drd_imageDraw,offset num7, 620, 440
	.endif

	.if eax == 8
	invoke drd_imageDraw,offset num8, 620, 440
	.endif

	.if eax == 9
	invoke drd_imageDraw,offset num9, 620, 440
	.endif
	

	
ret
scoreFunc endp


enemy1_shooting proc

mov ebx,shootingLoopSpeed


		cmp t,ebx
		jne afterTLoopForShooting
		mov shoot1,1
		mov t,10
		sub shootingLoopSpeed,100 
		afterTLoopForShooting:
		inc t

		cmp shot1s.reset_shoot,1
		jne AfterResetingShoot1Location
		mov eax, enemy1.y
		mov shot1s.y,eax
		AfterResetingShoot1Location:

		cmp shoot1,1
		jne AfterShootingShot1Enemy1
		mov shot1s.reset_shoot,0
		inc shot1s.x
		invoke drd_imageDraw,offset shot1, shot1s.x, shot1s.y
		AfterShootingShot1Enemy1:

		cmp shot1s.x,750
		jne AfterShot1WithRight
		mov ebx, enemy1.x
		;inc score
		mov shot1s.x,ebx
		mov shoot1,0
		mov shot1s.reset_shoot,1
		AfterShot1WithRight:

ret
enemy1_shooting endp


enemy2_shooting proc
	
		mov ebx,shootingLoopSpeed

		cmp b,ebx
		jne AFterBloopStatement 
		mov shoot2,1
		mov b,0
		sub shootingLoopSpeed,100
		AFterBloopStatement:
		inc b

		cmp shot2s.reset_shoot,1
		jne afterResetingshot2
		mov eax, enemy2.y
		mov shot2s.y,eax
		afterResetingshot2:

		cmp shoot2,1
		jne AfterShootingShot1Enemy2
		mov shot2s.reset_shoot,0
		dec shot2s.x
		invoke drd_imageDraw,offset shot1, shot2s.x, shot2s.y
		AfterShootingShot1Enemy2:

		cmp shot2s.x,0
		jne AfterShot1WithRight4
		mov ebx, enemy2.x
		mov shot2s.x,ebx
		mov shoot2,0
		mov shot2s.reset_shoot,1
		;inc score
		AfterShot1WithRight4:

ret
enemy2_shooting endp


enemy3_shooting proc
mov ebx,shootingLoopSpeed

		cmp j,8000
		jne AfterJLoopShot3
		mov shoot3,1
		mov j,0
		AfterJLoopShot3:
		inc j

		cmp shot3s.reset_shoot,1
		jne afterResetingshot23
		mov eax, enemy3.x
		mov shot3s.x,eax
		afterResetingshot23:

		cmp shoot3,1
		jne AfterShootingShot1Enemy3
		mov shot3s.reset_shoot,0
		inc shot3s.y
		invoke drd_imageDraw,offset shot1,shot3s.x, shot3s.y
		AfterShootingShot1Enemy3:

		
		cmp shot3s.y,350
		jl AfterShot3withBottom
		mov ebx, enemy3.x
		mov shot3s.x,ebx
		mov shoot3,0
		mov shot3s.y,40
		mov shot3s.reset_shoot,1
		;inc score
		AfterShot3withBottom:


ret
enemy3_shooting endp


check_Impact proc

;;;;;;;;;impact with player / shot1 ;;;;;;;

		invoke detect_collision, shot1s.x, shot1s.y,28 , 19, player.x, player.y, 62, 65
		
		cmp flag,0

		je afterDecLifeShot1
		mov ebx, enemy1.x
		mov shot1s.x,ebx
		mov shoot1,0
		mov shot1s.reset_shoot,1
		dec playerLife
		afterDecLifeShot1:

		invoke detect_collision, shot1s.x, shot1s.y,28 , 19, aip.x, aip.y, 62, 65
		cmp flag,0

		je afterbulbulofmyself
		mov ebx, enemy1.x
		mov shot1s.x,ebx
		mov shoot1,0
		mov shot1s.reset_shoot,1
		 afterbulbulofmyself:
		

		;;;;;;;;;;;impact with player / shot2;;;;;;;;

		invoke detect_collision, shot2s.x, shot2s.y,28 , 19, player.x, player.y, 62, 65
		
		cmp flag,0

		je afterDecLifeShot2
		mov ebx, enemy2.x
		mov shot2s.x,ebx
		mov shoot2,0
		mov shot2s.reset_shoot,1
		dec playerLife
		afterDecLifeShot2:


		invoke detect_collision, shot2s.x, shot2s.y,28 , 19, aip.x, aip.y, 62, 65

		cmp flag,0
		je asdlfhvaldhfvasljdfvlasdfvadsjl
		mov ebx, enemy2.x
		mov shot2s.x,ebx
		mov shoot2,0
		mov shot2s.reset_shoot,1
		asdlfhvaldhfvasljdfvlasdfvadsjl:

		;;;;;;;;;;;shot 3 impacts;;;;;;;;

		;;with player

		invoke detect_collision, shot3s.x, shot3s.y,28 , 19, player.x, player.y, 62, 65
		
		cmp flag,0

		je afterDecLifeShot3
		mov ebx, enemy3.y
		mov shot3s.y,ebx
		mov shoot3,ebx
		mov shot3s.reset_shoot,1
		dec playerLife
		afterDecLifeShot3:

		invoke detect_collision, shot3s.x, shot3s.y,28 , 19, aip.x, aip.y, 62, 65

		cmp flag,0
		je hugshnsjeuwnenweihw
		mov ebx, enemy3.y
		mov shot3s.y,ebx
		mov shoot3,ebx
		mov shot3s.reset_shoot,1

		hugshnsjeuwnenweihw:

ret
check_Impact endp


floor_Collision proc

cmp shot3s.x,190
	jl afterShotCollsionWithFloor
		cmp shot3s.x,430
		jg InShotCollsionStatement
		cmp shot3s.y,240
		jne AfterInCOWIFO
		mov ebx, enemy3.x
		mov shot3s.x,ebx
		mov shoot3,0
		mov shot3s.y,40
		mov shot3s.reset_shoot,1
		AfterInCOWIFO:
		InShotCollsionStatement:
	afterShotCollsionWithFloor:

	cmp player.x,190
	jl afterCollsionWithFloor1
		cmp player.x,430
		jg AFterCollisionwithfloor1instate
			mov eax,player.y
			add eax,65
			cmp eax,240
			jne AFtercollsionnumer2
			mov player.down,0
				
			AFtercollsionnumer2:
		AFterCollisionwithfloor1instate:
	afterCollsionWithFloor1:

				;;collsion with bottom of floor
				cmp player.x,190
				jl aftercollsionwithbottomoffloor1
					cmp player.x,430
					jg AfterCollsionWithBottomofFloor2
						cmp player.y,260
						jne AFterCollsiowbof3
						mov player.up,0
						mov player.down,1
						AFterCollsiowbof3:
					AfterCollsionWithBottomofFloor2:
				aftercollsionwithbottomoffloor1:

				cmp player.y,0
				jg afterCollsionwithtopofscreeen
				mov player.up,0
				mov player.down,1
				afterCollsionwithtopofscreeen:

				cmp player.x,430 
				jl aftercecnelgraivitystatement
				mov player.down,1
				aftercecnelgraivitystatement:

				cmp player.x,190
				jg aftercencelgravity2
				mov player.down,1
				aftercencelgravity2:

				cmp player.y,315
				jne aftercencelcenecelg
				mov player.down,0
				aftercencelcenecelg:

ret
floor_Collision endp

aiMovemenet proc
cmp aiLeft,1
jne afterTAI
mov aiRight,0
dec aip.x
afterTAI:

cmp aiRight,1
jne afterTAi1
mov aiLeft,0
inc aip.x
afterTAi1:


ret
aiMovemenet endp




jumpAi proc 
mov velocy,-5

mov eax, velocy
add aip.x,eax

inc velocy

ret
jumpAi endp

checkL proc

mov eax, player.y
cmp aip.y,eax
jg afterMoveDownAi

mov eax, player.x
cmp aip.x,eax
jg afterCheciMovinegToCenter
inc aip.x
afterCheciMovinegToCenter:

cmp aip.x,eax
jl afterCheciMovinegToCenter1
dec aip.x
afterCheciMovinegToCenter1:


cmp aiAbleToDown,1
jne afterMoveDownAi

inc aip.y
afterMoveDownAi:


cmp aip.y,eax
jl afterMoveUpAi
cmp aiAbleToUp,1
jne afterMoveUpAi
dec aip.y
afterMoveUpAi:

ret
checkL endp


 checkColAiWF proc

 cmp aip.y,260
 jne afterHGHGHGHG

	mov eax,230
	sub eax,62
	cmp aip.x,eax
	jl afterHGHGHGHG
		mov eax,230
		add eax,277
		cmp aip.x,eax
		jg afterHGHGHGHG
		 mov aiAbleToUp,0
		ret
 afterHGHGHGHG:
 mov aiAbleToUp,1
 ret
 checkColAiWF endp


 avoidTheFloor proc
 cmp aip.x,165
 jl afetetertertert
 dec aip.x
   ;mov aiAbleToUp,1
 afetetertertert:


 ret
 avoidTheFloor endp



 checkColWUpF proc


  cmp aip.y,175
 jne afterHGHGHGHG1

	mov eax,230
	sub eax,62
	cmp aip.x,eax
	jl afterHGHGHGHG1
		mov eax,230
		add eax,277
		cmp aip.x,eax
		jg afterHGHGHGHG1
		 mov aiAbleToDown,0
		ret
 afterHGHGHGHG1:
 mov aiAbleToDown,1

 ret
 checkColWUpF endp


 resetShootAiP proc

cmp AiShoot.reset_shoot,1
		jne afterRESeteitengagsdf
		mov eax,aip.y
		mov AiShoot.y,eax
		mov ebx, aip.x
		mov AiShoot.x,ebx
		
		afterRESeteitengagsdf:


 ret
 resetShootAiP endp
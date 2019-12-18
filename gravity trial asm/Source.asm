include \masm32\include\masm32rt.inc
include drd.inc
includelib drd.lib
include data.inc
include funcs.inc



.code 
main proc
invoke drd_init,800,500,0

invoke drd_setKeyHandler,offset key_handler

invoke loadImages



again:

invoke Sleep,1

invoke drd_pixelsClear,0
invoke drd_processMessages


invoke drd_imageDraw,offset background, 0, 0
	
invoke drd_imageSetTransparent,offset enemy1I, 0

invoke drd_imageSetTransparent,offset playerI, 0


	invoke drd_imageDraw,offset ground, 0, 380
	invoke drd_imageDraw,offset playerI, player.x, player.y

	invoke drd_imageDraw,offset floor1, 230, 240
	invoke drd_imageDraw,offset time, 400, 450

	invoke drd_imageDraw,offset playerI, aip.x, aip.y

	invoke drd_imageDraw,offset shot1, AiShoot.x, AiShoot.y


	;;;;;;;;;;;;;;pause game section;;;;;;;;;

	cmp pauseGame,1
	jne AfterPauseGame
		invoke pauseGameFunc
	AfterPauseGame:

		cmp startGame,1
		jne AfterStartGameQues
		invoke startGameFunc
		AfterStartGameQues:



		;;;;;losing section;;;;;;
		cmp playerLife,0
		jg AfterLosingSection
			mov pauseGame,1
		AfterLosingSection:



		;;;;;;;winning section;;;;;;;
		cmp score,0
		jg afterWinningSection
		mov pauseGame,1
		afterWinningSection:


	
		invoke scoreFunc

		invoke drawLife

	;;;;;;;;;;collision with floors;;;;;;;;;;


	invoke floor_Collision

	;;;;;;;;;;;enemies movement;;;;;;;;;;;;;;

	invoke enemy_movment,3
	invoke enemy_movment,2
	invoke enemy_movment,1


		invoke jump
	
		invoke gravity

		;;;;;;;;;;;;;;;;;;;enemies shooting section;;;;;;;;;;;;;;

		invoke enemy1_shooting
	
		invoke enemy2_shooting

		invoke enemy3_shooting

		invoke check_Impact

		;;;;;;;;;;;;;;;;;;

		invoke aiMovemenet
		

		
		inc AiShoot.x
		

		cmp ki,20
		jne afterAiLopC
		invoke checkL
		mov ki,10
		afterAiLopC:

		inc ki

		invoke checkColAiWF

		cmp aiAbleToUp,0
		jne aftertrtr
		invoke avoidTheFloor
		aftertrtr:

		invoke	checkColWUpF

		invoke resetShootAiP


		
		
		;;;;;;;;;;;;;;;;;;

	invoke drd_flip

jmp again

main endp
end main
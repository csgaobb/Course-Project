;>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
;					������Դ��Ϳγ���ƣ�������
;										         �����ߣ�����
;>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
		.486
		.model flat, stdcall
		option casemap :none
;>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
; include ͷ�ļ�
;>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
include		windows.inc
include		user32.inc
include		comdlg32.inc
include		kernel32.inc
include    D:\masm32\INCLUDE\masm32.inc

includelib	user32.lib
includelib	kernel32.lib
includelib	comdlg32.lib
includelib    D:\masm32\LIB\masm32.lib
;>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
; Equ ��ֵ����
;>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
ICO_MAIN	                		equ		   1000
IDD_DIALOG1           		equ         101
IDD_DIALOG2           		equ         102
IDD_DIALOG3           		equ         103
IDR_MENU1             		equ         102
IDC_EDIT1                		equ         1000
IDC_EDIT2        		  		equ 		   1002
IDC_BACKSPACE 	  		equ 		   1003
IDC_CE                     		equ 		   1004
IDC_C                		   		equ 		   1005
IDC_MC                     		equ 		   1006
IDC_MR					   		equ 		   1007
IDC_MS					   		equ 		   1008
IDC_M                        	equ         1009          ; "M+"
IDC_7                        		equ         1010
IDC_8                        		equ		   1011
IDC_9         	                  equ          1012      
IDC_chu                    		equ          1013
IDC_sqrt                     	equ			1014
IDC_4  	                 			equ			1015
IDC_5  	                			equ			1016
IDC_6 	                 			equ			1017
IDC_cheng  						equ			1018
IDC_mod  						equ			1019
IDC_1  								equ			1020
IDC_2  								equ			1021
IDC_3  								equ			1022
IDC_jian 							equ			1023
IDC_daoshu  					equ			1024
IDC_0  								equ			1030
IDC_jiajian  						equ			1031
IDC_dian  						equ			1032
IDC_jia  							equ			1033
IDC_equ  							equ			1034
ID_MENUCOPY      			equ     		40001
ID_MENUPASTE      		equ    		40002
ID_MENUSTANDARD    	equ    		40003
ID_MENUSCIENCE       	equ    		40004
ID_MENUDEVIDE        	equ     		40005
ID_MENUHELP         		equ    		40006
ID_MENUABOUT       		equ  			40007

;>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
; ���ݶ�
;>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
		.data?

hInstance 	dd	?
hWinMain	dd	?
hGlobal		dd	?
pGlobal		dd	?
pText			dd	?
hMenu			dd	?
;>>>>>>>>>>>>>>>>>>>>>>>>>>>>��ֵ��������>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 		.const
iNum0       db      '0',0
iNum1       db	    '1',0
iNum2		  db	    '2',0
iNum3		  db		'3',0
iNum4			db	'4',0
iNum5			db	'5',0
iNum6			db	'6',0
iNum7			db	'7',0
iNum8			db	'8',0
iNum9			db	'9',0
iPoint			db	'.',0
iNeg				db	'-',0                            ;�任�����ŵ�ʱ�����ϡ�
iFlag				db	'M',0								;�������ô洢�����ʱ������
iNull				db	0
iCalfor			dq			100.0
;>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
		.data
iDisplay				    db		'0',100 dup(?),0                 ;��ʾ���ַ���
iStore						  db		100 dup(?),0			 ;�ַ�����������Ŵӱ������õ����ַ�
iCopy						    db		20 dup(?)
ilength			        dd	  0						;���ڴ洢�ַ����ĳ���
imov								db		'0'
iNumber1      			dq  	     0.0                      ;8���ֽڵĸ���������,��һ��������
iNumber2		  			dq		     0.0                      ;8���ֽڵĸ���������,�ڶ���������
iResult		  			    dq		 0.0                      ;8���ֽڵĸ���������,������
iMemory					dq			 0.0						;���ڴ洢�ڴ��е����ݣ���MS��ʹ����Ҫ

;----------------------------���ü�����־--------------------------------------------------------------
iImPoint		db		0            ;��־��֮ǰ�Ƿ������С���㣬���Լ����Զ������С����Ĵ���
iEqual			db		0            ;���֮ǰ�Ƿ�������Ⱥţ�������������Ⱥ����������
iCal				db		0			   ;���֮ǰ�Ƿ����������ͬʱ��¼������������������������������������
iAlready		db		0				;�����0��ʾ�����������ռ���ϣ����������ˡ�
;------------------------------------------------------------------------------------------
;--------------------------������ʾ��Ϣ-------------------------------------------------
szCaption 		    db		'��������Ϊ0�������������!',0
szCaption2			db		'0û�е�����',0
szText				    db		'������',0
szText2				db		'Sorry',0
szScience				db		'��δʵ�ֿ�ѧ��',0
;------------------------------------------------------------------------------------------
;>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
; �����
;>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
		.code
;>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
_ProcHelp  	proc	uses ebx edi esi hWnd,wMsg,wParam,lParam

		mov	eax,wMsg
		.if	eax ==	WM_CLOSE
			       invoke	EndDialog,hWnd,NULL
		.else
			mov	eax,FALSE
			ret 
		.endif
		mov	eax,TRUE
		ret
_ProcHelp	endp
;>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

;>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
_ProcAbout 	proc	uses ebx edi esi hWnd,wMsg,wParam,lParam
		mov	eax,wMsg
		.if	eax ==	WM_CLOSE
			       invoke	EndDialog,hWnd,NULL
		.else
			mov	eax,FALSE
			ret 
		.endif
		mov	eax,TRUE
		ret
_ProcAbout	endp
;>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>			
;-------------------------------------------------------------------------------------------	
_ProcDlgMain	proc	uses ebx edi esi hWnd,wMsg,wParam,lParam

		mov	eax,wMsg
		.if	eax ==	WM_CLOSE
			       invoke	EndDialog,hWnd,NULL
		.elseif	eax ==	WM_INITDIALOG
			push	hWnd
			pop	hWinMain
			invoke	LoadIcon,hInstance,ICO_MAIN
			invoke	SendMessage,hWnd,WM_SETICON,ICON_BIG,eax
			invoke   SetDlgItemText,hWnd,IDC_EDIT1,addr iNum0
			invoke GetMenu,hWnd     ;��ʼ���õ��˵����hMenu
			mov	hMenu,eax
			;���������ǽ���ʼ��ʱ�����ó�Ĭ�ϵ�Ϊ��׼�ͼ����������ò˵��ϵĸ��ѡ�ϡ�
			invoke	SendMessage,hWnd,WM_COMMAND,ID_MENUSTANDARD,NULL
			mov iDisplay[0],0 	
		.elseif	eax ==	WM_COMMAND
			mov	eax,wParam
;-------------------------------------------------------------------------------------------				
			.if	ax ==	IDC_0
			        .if   iEqual ==0
			                invoke   lstrcat,addr iDisplay,addr iNum0
			                invoke   SetDlgItemText,hWnd,IDC_EDIT1,addr iDisplay
			         .endif
			         .if  iEqual !=0
			         		  mov iDisplay[0],0
			         		  invoke   SetDlgItemText,hWnd,IDC_EDIT1,addr iDisplay
			         		  invoke   lstrcat,addr iDisplay,addr iNum0
			                 invoke   SetDlgItemText,hWnd,IDC_EDIT1,addr iDisplay
			                 mov iEqual,0
			         .endif          
			.endif
;-------------------------------------------------------------------------------------------				
			.if	ax ==	IDC_1
			      .if   iEqual ==0
			                invoke   lstrcat,addr iDisplay,addr iNum1
			                invoke   SetDlgItemText,hWnd,IDC_EDIT1,addr iDisplay
			         .endif
			         .if  iEqual !=0
			         		  mov iDisplay[0],0
			         		  invoke   SetDlgItemText,hWnd,IDC_EDIT1,addr iDisplay
			         		  invoke   lstrcat,addr iDisplay,addr iNum1
			                 invoke   SetDlgItemText,hWnd,IDC_EDIT1,addr iDisplay
			                 mov iEqual,0
			         .endif         
			.endif
;-------------------------------------------------------------------------------------------				
			.if	ax ==	IDC_2
			       .if   iEqual ==0
			                invoke   lstrcat,addr iDisplay,addr iNum2
			                invoke   SetDlgItemText,hWnd,IDC_EDIT1,addr iDisplay
			         .endif
			         .if  iEqual !=0
			         		  mov iDisplay[0],0
			         		  invoke   SetDlgItemText,hWnd,IDC_EDIT1,addr iDisplay
			         		  invoke   lstrcat,addr iDisplay,addr iNum2
			                 invoke   SetDlgItemText,hWnd,IDC_EDIT1,addr iDisplay
			                 mov iEqual,0
			         .endif         
			.endif
;-------------------------------------------------------------------------------------------				
			.if	ax ==	IDC_3
			       .if   iEqual ==0
			                invoke   lstrcat,addr iDisplay,addr iNum3
			                invoke   SetDlgItemText,hWnd,IDC_EDIT1,addr iDisplay
			         .endif
			         .if  iEqual !=0
			         		  mov iDisplay[0],0
			         		  invoke   SetDlgItemText,hWnd,IDC_EDIT1,addr iDisplay
			         		  invoke   lstrcat,addr iDisplay,addr iNum3
			                 invoke   SetDlgItemText,hWnd,IDC_EDIT1,addr iDisplay
			                 mov iEqual,0
			         .endif         
			.endif
;-------------------------------------------------------------------------------------------				
			.if	ax ==	IDC_4
			       .if   iEqual ==0
			                invoke   lstrcat,addr iDisplay,addr iNum4
			                invoke   SetDlgItemText,hWnd,IDC_EDIT1,addr iDisplay
			         .endif
			         .if  iEqual !=0
			         		  mov iDisplay[0],0
			         		  invoke   SetDlgItemText,hWnd,IDC_EDIT1,addr iDisplay
			         		  invoke   lstrcat,addr iDisplay,addr iNum4
			                 invoke   SetDlgItemText,hWnd,IDC_EDIT1,addr iDisplay
			                 mov iEqual,0
			         .endif         
			.endif
;-------------------------------------------------------------------------------------------				
			.if	ax ==	IDC_5
			         .if   iEqual ==0
			                invoke   lstrcat,addr iDisplay,addr iNum5
			                invoke   SetDlgItemText,hWnd,IDC_EDIT1,addr iDisplay
			         .endif
			         .if  iEqual !=0
			         		  mov iDisplay[0],0
			         		  invoke   SetDlgItemText,hWnd,IDC_EDIT1,addr iDisplay
			         		  invoke   lstrcat,addr iDisplay,addr iNum5
			                 invoke   SetDlgItemText,hWnd,IDC_EDIT1,addr iDisplay
			                 mov iEqual,0
			         .endif         
			.endif
;-------------------------------------------------------------------------------------------				
			.if	ax ==	IDC_6
			       .if   iEqual ==0
			                invoke   lstrcat,addr iDisplay,addr iNum6
			                invoke   SetDlgItemText,hWnd,IDC_EDIT1,addr iDisplay
			         .endif
			         .if  iEqual !=0
			         		  mov iDisplay[0],0
			         		  invoke   SetDlgItemText,hWnd,IDC_EDIT1,addr iDisplay
			         		  invoke   lstrcat,addr iDisplay,addr iNum6
			                 invoke   SetDlgItemText,hWnd,IDC_EDIT1,addr iDisplay
			                 mov iEqual,0
			         .endif         
			.endif
;-------------------------------------------------------------------------------------------				
			.if	ax ==	IDC_7
			       .if   iEqual ==0
			                invoke   lstrcat,addr iDisplay,addr iNum7
			                invoke   SetDlgItemText,hWnd,IDC_EDIT1,addr iDisplay
			         .endif
			         .if  iEqual !=0
			         		  mov iDisplay[0],0
			         		  invoke   SetDlgItemText,hWnd,IDC_EDIT1,addr iDisplay
			         		  invoke   lstrcat,addr iDisplay,addr iNum7
			                 invoke   SetDlgItemText,hWnd,IDC_EDIT1,addr iDisplay
			                 mov iEqual,0
			         .endif         
			.endif
;-------------------------------------------------------------------------------------------				
			.if	ax ==	IDC_8
			       .if   iEqual ==0
			                invoke   lstrcat,addr iDisplay,addr iNum8
			                invoke   SetDlgItemText,hWnd,IDC_EDIT1,addr iDisplay
			         .endif
			         .if  iEqual !=0
			         		  mov iDisplay[0],0
			         		  invoke   SetDlgItemText,hWnd,IDC_EDIT1,addr iDisplay
			         		  invoke   lstrcat,addr iDisplay,addr iNum8
			                 invoke   SetDlgItemText,hWnd,IDC_EDIT1,addr iDisplay
			                 mov iEqual,0
			         .endif         
			.endif
;-------------------------------------------------------------------------------------------				
			.if	ax ==	IDC_9
			         .if   iEqual ==0
			                invoke   lstrcat,addr iDisplay,addr iNum9
			                invoke   SetDlgItemText,hWnd,IDC_EDIT1,addr iDisplay
			         .endif
			         .if  iEqual !=0
			         		  mov iDisplay[0],0
			         		  invoke   SetDlgItemText,hWnd,IDC_EDIT1,addr iDisplay
			         		  invoke   lstrcat,addr iDisplay,addr iNum9
			                 invoke   SetDlgItemText,hWnd,IDC_EDIT1,addr iDisplay
			                 mov iEqual,0
			         .endif         
			.endif
;-------------------------------------------------------------------------------------------				
			.if	ax ==	IDC_dian
			       			 invoke GetDlgItemText,hWnd,IDC_EDIT1,addr iStore,20+1
			       			 invoke StrToFloat,addr iStore,addr iResult
			       			 finit
			       			 fld  iResult
			       			 ftst		;��0.0�Ƚϣ����Ϊ0��C3,C2,C1Ϊ1��0��0	
			       			 fstsw ax
			       			 and ax,4500h	
			       			 .if ax==4000h
			       					mov iDisplay[0],'0'
			       					invoke   lstrcat,addr iDisplay,addr iPoint
			        				invoke   SetDlgItemText,hWnd,IDC_EDIT1,addr iDisplay		
			       			 .else				
			       			 invoke   lstrcat,addr iDisplay,addr iPoint
			        		 invoke   SetDlgItemText,hWnd,IDC_EDIT1,addr iDisplay
			        		 .endif
			       		
			        
			.endif
;-------------------------------------------------------------------------------------------				
			.if	ax ==	IDC_jia            
			               mov iCal , 1      ;���������Ϊ�ӣ���־λ��ӦΪ1
			               ;����ʾ���ж�ȡ20���ַ���ת���ɶ�Ӧ�����ݡ�
			       			invoke GetDlgItemText,hWnd,IDC_EDIT1,addr iStore,20+1
			       			invoke StrToFloat,addr iStore,addr iNumber1
			       			;��iDisplay�ÿգ�������һ�����Ķ���
			       			mov iDisplay[0],0
			       			
			.endif
;-------------------------------------------------------------------------------------------				
			.if	ax ==	IDC_jian           
			                mov iCal ,2       ;���������Ϊ�ӣ���־λ��ӦΪ2
			               ;����ʾ���ж�ȡ20���ַ���ת���ɶ�Ӧ�����ݡ�
			       			invoke GetDlgItemText,hWnd,IDC_EDIT1,addr iStore,20+1
			       			invoke StrToFloat,addr iStore,addr iNumber1
			       			mov iDisplay[0],0 
			.endif
;-------------------------------------------------------------------------------------------				
			.if	ax ==	IDC_cheng            
			               mov iCal ,3       ;���������Ϊ�ӣ���־λ��ӦΪ3
			               ;����ʾ���ж�ȡ20���ַ���ת���ɶ�Ӧ�����ݡ�
			       			invoke GetDlgItemText,hWnd,IDC_EDIT1,addr iStore,20+1
			       			invoke StrToFloat,addr iStore,addr iNumber1
			       			mov iDisplay[0],0
			.endif
;-------------------------------------------------------------------------------------------				
			.if	ax ==	IDC_chu             
			               mov iCal , 4        ;���������Ϊ�ӣ���־λ��ӦΪ4
			               ;����ʾ���ж�ȡ20���ַ���ת���ɶ�Ӧ�����ݡ�
			       			invoke GetDlgItemText,hWnd,IDC_EDIT1,addr iStore,20+1
			       			invoke StrToFloat,addr iStore,addr iNumber1	
;�����������£�ÿ�ε����������ַ�ʽ���㡣����ÿ�γ�����ʱ����ʾ����ǰ�涼���һ��0
			       			;mov iDisplay[0],'0'
			       			;mov iDisplay[1],0
			       			mov iDisplay[0],0
			       			
			.endif
;-------------------------------------------------------------------------------------------				
			.if	ax ==	IDC_sqrt  ;ֱ�ӽ���ǰ�ļ�����������ʾ����
			     			invoke GetDlgItemText,hWnd,IDC_EDIT1,addr iStore,20+1
			     			invoke StrToFloat,addr iStore,addr iResult
			     			finit
			     			fld iResult
			     			fsqrt
			     			fst iResult
			     			finit
			     			invoke FloatToStr,iResult,addr iDisplay
			     			invoke SetDlgItemText,hWnd,IDC_EDIT1,addr iDisplay
			     			mov iEqual,2               ;ȡƽ��ʱ������Ϊ��0
			.endif
;-------------------------------------------------------------------------------------------				
			.if	ax ==	IDC_BACKSPACE
			      			invoke GetDlgItemText,hWnd,IDC_EDIT1,addr iStore,20+1
			      			invoke lstrlen,addr iStore
			      			.if eax>1
			      			mov  iStore[eax-1],0
			      			mov  iDisplay[eax-1],0
			      			invoke SetDlgItemText,hWnd,IDC_EDIT1,addr iStore
			      			.else
			      		   invoke SetDlgItemText,hWnd,IDC_EDIT1,addr iNum0  ;��ʾ����
			      		   mov iDisplay[0],0			;�����������ÿ�
			      		   .endif
			.endif
;-------------------------------------------------------------------------------------------				
			.if	ax ==	IDC_CE
			      mov iDisplay[0],'0'
			      mov iDisplay[1],0
			      invoke SetDlgItemText,hWnd,IDC_EDIT1,addr iDisplay
			      mov iDisplay[0],0
			      finit
			      fldz
			      fst iNumber2        ;����ǰ���������
			      finit
			.endif
;-------------------------------------------------------------------------------------------				
			.if	ax ==	IDC_C        ;���е����㶼���㣬ȫ�����¿�ʼ
			       mov iDisplay[0],'0'
			       mov iDisplay[1],0
			       invoke SetDlgItemText,hWnd,IDC_EDIT1,addr iDisplay
			       mov iDisplay[0],0
			       finit
			       fldz  ;����
			       fst iNumber1
			       fst iNumber2
			       finit
			       mov iEqual,0
			.endif
;-------------------------------------------------------------------------------------------				
			.if	ax ==	IDC_mod
			      	;�ٷ��������㣬��ʵ���ǵ��������ť��ʹ����ʾ�����ֵİٷ�֮��ǰ����������
			      	invoke GetDlgItemText,hWnd,IDC_EDIT1,addr iStore,20+1
			      	invoke StrToFloat,addr iStore,addr iResult
			      	finit
			      	fld iCalfor
			      	fld iNumber1
			      	fld iResult
			       fmul ST(0),ST(1)
			       fdiv	ST(0),ST(2)
			       fst iResult			;�����ĳ���İٷ�֮ĳ���õ��Ľ��
			      	invoke FloatToStr,iResult,addr iDisplay
			      	invoke  SetDlgItemText,hWnd,IDC_EDIT1,addr iDisplay
			.endif
;-------------------------------------------------------------------------------------------				
			.if	ax ==	IDC_daoshu
			      	  invoke GetDlgItemText,hWnd,IDC_EDIT1,addr iStore,20+1
			     	  invoke StrToFloat,addr iStore,addr iResult
			     	  finit
			       	  fld  iResult
			       	  ftst		     ;��0.0�Ƚϣ����Ϊ0��C3,C2,C1Ϊ1��0��0	
			       	  fstsw ax
			       	  and ax,4500h
			       	  finit	
			       	 .if ax==4000h
			       					invoke MessageBox,NULL,addr szCaption2,addr szText,MB_OK
			       	 .elseif		
			     	  finit 
			     	  fld iResult 
			     	  fld1
			     	  fdiv ST(0),ST(1)
			     	  fst iResult 
			     	  finit 
			     	  invoke FloatToStr,iResult,addr iDisplay 
			     	  invoke   SetDlgItemText,hWnd,IDC_EDIT1,addr iDisplay
			         mov iEqual,3               ;ȡ����ʱ������Ϊ��0
			         .endif
			.endif
;-------------------------------------------------------------------------------------------				
			.if	ax ==	IDC_jiajian
			           invoke GetDlgItemText,hWnd,IDC_EDIT1,addr iStore,20+1
			     	    invoke StrToFloat,addr iStore,addr iResult
			     	    finit
			     	    fld iResult
			     	    ftst		;�ȽϺ�0�Ĵ�С
			     	    fstsw ax
			     	    and ax,4500h
			     	    finit
			     	    .if ax==0   					;iResult>0,Ҳ������ʾ��������һ������
			     	    		mov iDisplay[0],'-'
			     	    		mov iDisplay[1],0
			     	    		invoke   SetDlgItemText,hWnd,IDC_EDIT1,addr iNull
			     	    		invoke lstrcat ,addr iDisplay,addr iStore
			     	    		invoke   SetDlgItemText,hWnd,IDC_EDIT1,addr iDisplay
			     	    .elseif  ax ==100h		;iResult<0,Ҳ������ʾ��������һ������
			     	    		mov iStore[0],'+' 
			     	    		invoke StrToFloat,addr iStore,addr iResult 	;����Ӧ������ת�����ַ�������
			     	    		invoke FloatToStr,iResult,addr iDisplay 
			     	    		invoke  SetDlgItemText,hWnd,IDC_EDIT1,addr iDisplay
			     	    .endif		
			.endif
;-------------------------------------------------------------------------------------------				
			.if	ax ==	IDC_equ
							.if iEqual == 1    ;���������ĵȺ�����,���ǽ���ǰ�Ľ����Ϊ��һ����
								invoke GetDlgItemText,hWnd,IDC_EDIT1,addr iStore,20+1
			       				invoke StrToFloat,addr iStore,addr iNumber1
							.else
								mov iEqual,1
			               	;�õ��ڶ���������
			               	invoke GetDlgItemText,hWnd,IDC_EDIT1,addr iStore,20+1
			       				invoke StrToFloat,addr iStore,addr iNumber2
			       			.endif		
			       				.if   iCal ==1
			       					finit
			       					fld	iNumber2		;�ڶ�����ΪST(1)
			       					fld	iNumber1    ;��һ����ΪST(0)
			       					fadd  ST(0),ST(1)    
			       					fst	iResult      ;ST(0)��Ϊ�����ŵ�iResult��
			       					finit
			       					invoke FloatToStr,iResult,addr iDisplay
			       					invoke SetDlgItemText,hWnd,IDC_EDIT1,addr iDisplay
			       				.endif		
			       				.if   iCal ==2
			       					finit
			       					fld	iNumber2		;�ڶ�����ΪST(1)
			       					fld	iNumber1    ;��һ����ΪST(0)
			       					fsub  ST(0),ST(1)
			       					fst	iResult      ;ST(0)��Ϊ�����ŵ�iResult��
			       					finit
			       					invoke FloatToStr,iResult,addr iDisplay
			       					invoke SetDlgItemText,hWnd,IDC_EDIT1,addr iDisplay
			       				.endif			
			       				.if   iCal ==3
			       					finit
			       					fld	iNumber2		;�ڶ�����ΪST(1)
			       					fld	iNumber1    ;��һ����ΪST(0)
			       					fmul  ST(0),ST(1)
			       					fst	iResult      ;ST(0)��Ϊ�����ŵ�iResult��
			       					finit
			       					invoke FloatToStr,iResult, addr iDisplay
			       					invoke SetDlgItemText,hWnd,IDC_EDIT1,addr iDisplay
			       				.endif			
			       				.if   iCal == 4
			       					finit
			       					fld  iNumber2
			       					ftst		;��0.0�Ƚϣ����Ϊ0��C3,C2,C1Ϊ1��0��0	
			       					fstsw ax
			       					and ax,4500h	
			       					.if ax==4000h
			       							invoke MessageBox,NULL,addr szCaption,addr szText,MB_OK
			       					.elseif		
			       					finit
			       					fld	iNumber2		;�ڶ�����ΪST(1)
			       					fld	iNumber1    ;��һ����ΪST(0)
			       					fdiv  ST(0),ST(1)
			       					fst	iResult      ;ST(0)��Ϊ�����ŵ�iResult��
			       					finit
			       					invoke FloatToStr,iResult, addr iDisplay
			       					invoke SetDlgItemText,hWnd,IDC_EDIT1,addr iDisplay
			       					.endif
			       				.endif		             
			.endif
;-------------------------------------------------------------------------------------------				
			.if	ax ==	IDC_MC
			         finit
			         fldz
			         fst iMemory
			         mov iDisplay[0],0
			         finit
			         invoke SetDlgItemText,hWnd,IDC_EDIT2,addr iDisplay  
			.endif
;-------------------------------------------------------------------------------------------				
			.if	ax ==	IDC_MR
			              invoke FloatToStr,iMemory,addr iDisplay
			       		   invoke SetDlgItemText,hWnd,IDC_EDIT1,addr iDisplay 
			.endif
;-------------------------------------------------------------------------------------------				
			.if	ax ==	IDC_MS
			          invoke GetDlgItemText,hWnd,IDC_EDIT1,addr iStore,20+1
			     	  invoke StrToFloat,addr iStore,addr iMemory
			     	  invoke SetDlgItemText,hWnd,IDC_EDIT2,addr iFlag  
			.endif
;-------------------------------------------------------------------------------------------				
			.if	ax ==	IDC_M
			          ;���M+�Ĳ����������ǰ�洢�ˣ����ۼӲ����룬���򽫵�ǰ���洢����
			          invoke GetDlgItemText,hWnd,IDC_EDIT2,addr iStore,20+1
			          .if  iStore[0]!='M'        ;�����ʼû�д洢���ݣ�����ʹ洢����ʾ������
			                 invoke GetDlgItemText,hWnd,IDC_EDIT1,addr iDisplay,20+1
			                 invoke StrToFloat,addr iDisplay,addr iMemory
			                 invoke SetDlgItemText,hWnd,IDC_EDIT2,addr iFlag  
			          .else       
			                invoke GetDlgItemText,hWnd,IDC_EDIT1,addr iStore,20+1
			                invoke StrToFloat,addr iStore,addr iResult
			                finit
			          		 fld iResult
			          		 fld iMemory
			         		 fadd ST(0),ST(1)
			          		 fst  iMemory
			          .endif
			.endif
;--------------------------------------------------------------------------------------------
			.if ax ==ID_MENUCOPY
				invoke GetDlgItemText,hWnd,IDC_EDIT1,addr iStore,20+1
				invoke lstrlen,addr iStore
				add eax,1
				mov ecx,GHND
				or ecx,GMEM_SHARE
				invoke GlobalAlloc,ecx,eax
               mov hGlobal,eax
               invoke GlobalLock , hGlobal
               mov pGlobal,eax       ;����ɹ��Ļ���GlobalLock�ķ���ֵ����ָ�룬��������Ĳ���Ҫ
               invoke lstrcpy ,pGlobal,addr iStore 
               invoke GlobalUnlock ,hGlobal
               invoke OpenClipboard, hWnd 
               invoke EmptyClipboard 
               invoke SetClipboardData, CF_TEXT, hGlobal 
               invoke CloseClipboard 
			.endif 
;--------------------------------------------------------------------------------------------				
			.if ax==ID_MENUPASTE      		
			 		invoke OpenClipboard ,hWnd
            		invoke GetClipboardData,CF_TEXT
            		mov hGlobal,eax
            		.if hGlobal!=0
           				invoke GlobalLock ,hGlobal			;��λ�������������
          			    mov pGlobal,eax
          			    .if pText!=NULL                ;����ǿ����ÿ�
          			    		mov pText[0],0 
          			    		mov pText[1],0
          			    .endif
          			    mov pText,offset iDisplay			;pText��Ϊָ�룬����ȡ��ַ
                       invoke lstrcpy,pText,pGlobal
                       invoke SetDlgItemText,hWnd,IDC_EDIT1,pText
                 .endif
               invoke CloseClipboard 
            .endif   
;-------------------------------------------------------------------------------------------	
			.if ax==ID_MENUSTANDARD
					movzx eax,ax
					mov ebx,eax
					invoke GetMenuState,hMenu,ebx,MF_BYCOMMAND
					.if eax & MF_CHECKED
							mov eax,MF_UNCHECKED
					.else
							mov eax,MF_CHECKED
					.endif
					;��������������ʵ�ֽ�ĳ��ѡ�ϻ��߲�ѡ�ϣ��������Ĳ˵����޹أ�ǰ���ǶԹ���		
					;invoke	CheckMenuItem,hMenu,ebx,eax		;eaxΪѡ��״̬��ebxΪ�����ID
					;�������������ǽ���һ�����ó�RadioItem,���������о�ֻ��ѡ��һ���ˣ�ֻ��ȡһ��
					invoke	CheckMenuRadioItem,hMenu,\					
					ID_MENUSTANDARD,ID_MENUSCIENCE,ID_MENUSTANDARD,MF_BYCOMMAND				
			.endif
;-------------------------------------------------------------------------------------------	
			.if ax==ID_MENUSCIENCE
					movzx eax,ax
					mov ebx,eax
					invoke GetMenuState,hMenu,ebx,MF_BYCOMMAND
					.if eax & MF_CHECKED
							mov eax,MF_UNCHECKED
					.else
							mov eax,MF_CHECKED
					.endif
					;��������������ʵ�ֽ�ĳ��ѡ�ϻ��߲�ѡ�ϣ��������Ĳ˵����޹أ�ǰ���ǶԹ���		
				    ;invoke	CheckMenuItem,hMenu,ebx,eax		;eaxΪѡ��״̬��ebxΪ�����ID
					;�������������ǽ��ڶ���Ҳ���ó�RadioItem,���������о�ֻ��ѡ��һ���ˣ�ֻ��ȡһ��
					invoke	CheckMenuRadioItem,hMenu,\					
					ID_MENUSTANDARD,ID_MENUSCIENCE,ID_MENUSCIENCE,MF_BYCOMMAND				
			.endif
;-------------------------------------------------------------------------------------------			
			.if ax==ID_MENUDEVIDE
					movzx eax,ax
					mov ebx,eax
					invoke GetMenuState,hMenu,ebx,MF_BYCOMMAND
					.if eax & MF_CHECKED
							mov eax,MF_UNCHECKED
					.else
							mov eax,MF_CHECKED
					.endif
					invoke	CheckMenuItem,hMenu,ebx,eax
			.endif
;-------------------------------------------------------------------------------------------			
			.if ax==ID_MENUHELP
					invoke	DialogBoxParam,hInstance,IDD_DIALOG3,NULL,offset _ProcHelp,NULL
			.endif 
;-------------------------------------------------------------------------------------------			        		
  			.if ax==ID_MENUABOUT
  					invoke	DialogBoxParam,hInstance,IDD_DIALOG2,NULL,offset _ProcAbout,NULL
  			.endif
;-------------------------------------------------------------------------------------------				
		.else
			mov	eax,FALSE
			ret 
		.endif
		mov	eax,TRUE
		ret

_ProcDlgMain	endp
;>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

;>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
start:
		invoke	GetModuleHandle,NULL
		mov	hInstance,eax
		invoke	DialogBoxParam,hInstance,IDD_DIALOG1,NULL,offset _ProcDlgMain,NULL
		invoke	ExitProcess,NULL
;>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
		end	start
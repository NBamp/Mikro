%%%
%%%
%%% τρέχετε το πρόγραμμα ως:
%%% signalprobs(input1sp,input2sp)
%%%
%%% Παραδείγματα:
%%% >> signalprobs(0.5,0.5)
%%% AND Gate for input probabilities (0.500000 0.500000):
%%% ans =  0.25000
%%% OR Gate for input probabilities (0.500000 0.500000):
%%% ans =  0.75000
%%% XOR Gate for input probabilities (0.500000 0.500000):
%%% NAND Gate for input probabilities (0.500000 0.500000):
%%% NOR Gate for input probabilities (0.500000 0.500000):
%%%
%%%
%%% >> signalprobs(0,0)
%%% AND Gate for input probabilities (0.00000 0.00000):
%%% ans =  0
%%% OR Gate for input probabilities (0.00000 0.00000):
%%% ans =  0
%%% XOR Gate for input probabilities (0.00000 0.00000):
%%% NAND Gate for input probabilities (0.00000 0.00000):
%%% NOR Gate for input probabilities (0.00000 0.00000):
%%%
%%% >> signalprobs(1,1)
%%% AND Gate for input probabilities (1.00000 1.00000):
%%% ans =  1
%%% OR Gate for input probabilities (1.00000 1.00000):
%%% ans =  1
%%% XOR Gate for input probabilities (1.00000 1.00000):
%%% NAND Gate for input probabilities (1.00000 1.00000):
%%% NOR Gate for input probabilities (1.00000 1.00000):
%%%
%%%
%%%
%%% Οι συναρτήσεις που υπολογίζουν τα signal probabilities
%%% AND και OR πυλών δύο εισόδων έχουν ήδη υλοποιηθεί παρακάτω.
%%% Οι συναρτήσεις που υπολογίζουν τα signal probabilities
%%% XOR, NAND και NOR πυλών δύο εισόδων είναι ημιτελής.
%%% (α) Σας ζητείτε να συμπληρώσετε τις υπόλοιπες ημιτελής συναρτήσεις για τον υπολογισμό
%%% των signal probabilities XOR,NAND και NOR 2 εισόδων πυλών.
%%% (β) γράψτε συναρτήσεις για τον υπολογισμό των signal probabilities
%%% AND, OR, XOR, NAND, NOR πυλών 3 εισόδων
%%% (γ) γράψτε συναρτήσεις για τον υπολογισμό των signal probabilities
%%% AND, OR, XOR, NAND, NOR πυλών Ν εισόδων


function s=signalprobs(input1sp, input2sp, varargin)

  % Οι παρακάτω συναρτήσεις πρέπει να ολοκληρωθούν για το (α)
  if  (nargin==2)
    sp2AND(input1sp, input2sp);
    sp2OR(input1sp, input2sp);
    sp2XOR(input1sp, input2sp);
    sp2NAND(input1sp, input2sp);
    sp2NOR(input1sp, input2sp);

  % Οι παρακάτω συναρτήσεις πρέπει να γραφούν εξ'ολοκλήρου για το (β)
  %sp3AND(input1sp, input2sp, input3sp)
  %sp3OR(input1sp, input2sp, input3sp)
  %sp3XOR(input1sp, input2sp, input3sp);
  %sp3NAND(input1sp, input2sp, input3sp);
  %sp3NOR(input1sp, input2sp, input3sp);


  elseif (nargin==3)
    sp3AND(input1sp,input2sp,varargin{1});
    sp3OR(input1sp,input2sp,varargin{1});
    sp3XOR(input1sp,input2sp,varargin{1});
    sp3NAND(input1sp,input2sp,varargin{1});
    sp3NOR(input1sp,input2sp,varargin{1});

  % Οι παρακάτω συναρτήσεις πρέπει να γραφούν εξ'ολοκλήρου για το (γ)
  %% προσοχή: πρέπει να παίζουν ανεξάρτητα του πόσες εισόδους τους δίνετε
  %spAND(input1sp, input2sp, input3sp, input4sp ...)
  %spOR(input1sp, input2sp, input3sp, input4sp ...)
  %spXOR(input1sp, input2sp, input3sp, input4sp, ...);
  %spNAND(input1sp, input2sp, input3sp, input4sp, ...);
  %spNOR(input1sp, input2sp, input3sp, input4sp, ...);

  else
    spAND(input1sp,input2sp,varargin{:});
    spNAND(input1sp,input2sp,varargin{:});
    spOR(input1sp,input2sp,varargin{:});
    spNOR(input1sp,input2sp,varargin{:});
    spXOR(input1sp,input2sp,varargin{:});

endif



  endfunction


% 2-input AND gate truth table
% 0 0:0
% 0 1:0
% 1 0:0
% 1 1:1
%% signal probability calculator for a 2-input AND gate
%% input1sp: signal probability of first input signal
%% input2sp: signal probability of second input signal
%%        s: output signal probability
function [s,Esw]=sp2AND(input1sp, input2sp)
  printf("AND Gate for input probabilities (%f %f):\n",input1sp,input2sp)
  s = input1sp*input2sp
  Esw = 2*s * (1-s)
  endfunction

% 2-input OR gate truth table
% 0 0:0
% 0 1:1
% 1 0:1
% 1 1:1
%% signal probability calculator for a 2-input OR gate
%% input1sp: signal probability of first input signal
%% input2sp: signal probability of second input signal
%%        s: output signal probability
function [s,Esw]=sp2OR(input1sp, input2sp)
  printf("OR Gate for input probabilities (%f %f):\n",input1sp,input2sp)
  s = 1-(1-input1sp)*(1-input2sp)
  Esw = 2*s * (1-s)
endfunction


% 2-input XOR gate truth table
% 0 0:0
% 0 1:1
% 1 0:1
% 1 1:0
%% signal probability calculator for a 2-input XOR gate
%% input1sp: signal probability of first input signal
%% input2sp: signal probability of second input signal
%%        s: output signal probability
function [s,Esw]=sp2XOR(input1sp, input2sp)
  printf("XOR Gate for input probabilities (%f %f):\n",input1sp,input2sp)
  s = 1 - 2 *(input1sp * input2sp)
  Esw = 2*s * (1-s)
endfunction


% 2-input NAND gate truth table
% 0 0:1
% 0 1:1
% 1 0:1
% 1 1:0
%% signal probability calculator for a 2-input XOR gate
%% input1sp: signal probability of first input signal
%% input2sp: signal probability of second input signal
%%        s: output signal probability
function [s,Esw]=sp2NAND(input1sp, input2sp)
  printf("NAND Gate for input probabilities (%f %f):\n",input1sp,input2sp)
  s = 1 - (input1sp * input2sp)
  Esw = 2*s * (1-s)
endfunction



% 2-input NOR gate truth table
% 0 0:1
% 0 1:0
% 1 0:0
% 1 1:0
%% signal probability calculator for a 2-input NOR gate
%% input1sp: signal probability of first input signal
%% input2sp: signal probability of second input signal
%%        s: output signal probability
function [s,Esw]=sp2NOR(input1sp, input2sp)
  printf("NOR Gate for input probabilities (%f %f):\n",input1sp,input2sp)
  s = (1-input1sp)*(1-input2sp)
  Esw = 2*s * (1-s)
endfunction


% 3-input AND gate truth table

% 0 0 0 :0
% 0 0 1 :0
% 0 1 0 :0
% 0 1 1 :0
% 1 0 0 :0
% 1 0 1 :0
% 1 1 0 :0
% 1 1 1 :1

%% signal probability calculator for a 3-input AND gate
%% input1sp: signal probability of first input signal
%% input2sp: signal probability of second input signal
%% input3sp: signal probability of second input signal
%%        b: output signal probability



function [s,Esw]=sp3AND(input1sp, input2sp, input3sp)
  printf("AND Gate 3 for input probabilities (%f %f %f):\n",input1sp,input2sp,input3sp)
  s = input1sp*input2sp*input3sp
  Esw = 2*s * (1-s)
endfunction

% 3-input OR gate truth table

% 0 0 0 :0
% 0 0 1 :1
% 0 1 0 :1
% 0 1 1 :1
% 1 0 0 :1
% 1 0 1 :1
% 1 1 0 :1
% 1 1 1 :1

%% signal probability calculator for a 3-input OR gate
%% input1sp: signal probability of first input signal
%% input2sp: signal probability of second input signal
%% input3sp: signal probability of second input signal
%%        b: output signal probability

function [s,Esw]=sp3OR(input1sp, input2sp, input3sp)
  printf("OR Gate 3 for input probabilities (%f %f %f):\n",input1sp,input2sp,input3sp)
  s = input1sp + input2sp + input3sp - (input1sp*input2sp) - (input2sp*input3sp) - (input1sp*input3sp) + (input1sp*input2sp*input3sp)
  Esw = 2*s * (1-s)
endfunction


% 3-input XOR gate truth table

% 0 0 0 :0
% 0 0 1 :1
% 0 1 0 :1
% 0 1 1 :0
% 1 0 0 :1
% 1 0 1 :0
% 1 1 0 :0
% 1 1 1 :1

%% signal probability calculator for a 3-input XOR gate
%% input1sp: signal probability of first input signal
%% input2sp: signal probability of second input signal
%% input3sp: signal probability of second input signal
%%        b: output signal probability

function [s,Esw]=sp3XOR(input1sp, input2sp, input3sp)
  printf("XOR Gate 3 for input probabilities (%f %f %f):\n",input1sp,input2sp,input3sp)
  s = ((1-input1sp)*(1-input2sp)*input3sp) + ((1-input1sp)*(1-input3sp)*input2sp) + ((1-input2sp)*(1-input3sp)*input1sp) + input1sp*input2sp*input3sp
  Esw = 2*s * (1-s)
endfunction

% 3-input NAND gate truth table

% 0 0 0 :1
% 0 0 1 :1
% 0 1 0 :1
% 0 1 1 :1
% 1 0 0 :1
% 1 0 1 :1
% 1 1 0 :1
% 1 1 1 :0

%% signal probability calculator for a 3-input NAND gate
%% input1sp: signal probability of first input signal
%% input2sp: signal probability of second input signal
%% input3sp: signal probability of second input signal
%%        b: output signal probability

function [s,Esw]=sp3NAND(input1sp, input2sp, input3sp)
  printf("NAND Gate 3 for input probabilities (%f %f %f):\n",input1sp,input2sp,input3sp)
  s = 1 - (input1sp*input2sp*input3sp)
  Esw = 2*s * (1-s)
endfunction



% 3-input NOR gate truth table

% 0 0 0 :1
% 0 0 1 :0
% 0 1 0 :0
% 0 1 1 :0
% 1 0 0 :0
% 1 0 1 :0
% 1 1 0 :0
% 1 1 1 :0

%% signal probability calculator for a 3-input NOR gate
%% input1sp: signal probability of first input signal
%% input2sp: signal probability of second input signal
%% input3sp: signal probability of second input signal
%%        s: output signal probability

function [s,Esw]=sp3NOR(input1sp, input2sp, input3sp)
  printf("NOR Gate 3 for input probabilities (%f %f %f):\n",input1sp,input2sp,input3sp)
  s = (1-input1sp) * (1-input2sp) * (1-input3sp)
  Esw = 2*s * (1-s)
endfunction


% Ν-input AND gate truth table
%% signal probability calculator for a Ν-input NOR gate
%% input1sp: signal probability of first input signal
%% input2sp: signal probability of second input signal
%% input3sp: signal probability of second input signal
%% ..
%%        s: output signal probability

function [s,Esw]=spAND(varargin)
  s = 1
  for i=1:nargin
    s *= varargin{i}
  endfor
  printf("AND Gate for N inputs\n")
  s
  Esw = 2*s * (1-s)
endfunction








% Ν-input NAND gate truth table
%% signal probability calculator for a Ν-input  NAND gate
%% input1sp: signal probability of first input signal
%% input2sp: signal probability of second input signal
%% input3sp: signal probability of second input signal
%% ..
%%        s: output signal probability

function [s,Esw]=spNAND(varargin)
  [s1,~] = spAND(varargin{:})
  s = 1 - s1
  printf("NAND Gate for N inputs\n")
  s
  Esw = 2*s * (1-s)

endfunction






% Ν-input OR gate truth table
%% signal probability calculator for a Ν-input OR gate
%% input1sp: signal probability of first input signal
%% input2sp: signal probability of second input signal
%% input3sp: signal probability of second input signal
%% ..
%%        s: output signal probability

function [s,Esw]=spOR(varargin)
  [s1,~] = spNOR(varargin{:})
  s = 1 - s1
  printf("OR Gate for N inputs\n")
  s
  Esw = 2*s * (1-s)

endfunction








% Ν-input NOR gate truth table
%% signal probability calculator for a Ν-input  NOR gate
%% input1sp: signal probability of first input signal
%% input2sp: signal probability of second input signal
%% input3sp: signal probability of second input signal
%% ..
%%        s: output signal probability

function [s,Esw]=spNOR(varargin)
  s = 1
  for i=1:nargin
    s *= (1 - varargin{i})
  endfor
  printf("NOR Gate for N inputs\n")
  s
  Esw = 2*s * (1-s)

endfunction


% Ν-input XOR gate truth table
%% signal probability calculator for a Ν-input  XOR gate
%% input1sp: signal probability of first input signal
%% input2sp: signal probability of second input signal
%% input3sp: signal probability of second input signal
%% ..
%%        s: output signal probability



function [s,Esw]=spXOR(varargin)

  if mod(nargin,3) == 0
     [s1,~] = spAND(varargin{:})
  else
     s1 = 0
  endif


  for i=1:nargin
    if (i!=1 || i!=nargin )
      [s3,~] = spNOR(varargin{1:i-1})
      [s4,~] = spNOR(varargin{i+1:nargin})
      s5 = s3 * s4
    elseif (i==nargin)
      [s5,~] = spNOR(varargin{1:nargin-1})
    else
      [s5,~] = spNOR(varargin{2:nargin})
    endif
    s1 += varargin{i}*s5
  endfor
  printf("XOR Gate for N inputs\n")
  s = s1
  Esw = 2*s * (1-s)

endfunction

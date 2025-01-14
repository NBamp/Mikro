%Complicated circuit model with one logic gate 2inputs-AND and one logic gate 1input-NOT as input to one logic gate 2inputs-AND as output
function [d,e,f]=circuit(a,b,c)
  e = sp2AND(a,b);
  f = spNOT(c);
  d = sp2AND(e,f);
  printf("Output for circuit is (%f)\n",d)

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
function s=sp2AND(input1sp, input2sp)
  printf("AND Gate for input probabilities (%f %f):\n",input1sp,input2sp)
  s = input1sp*input2sp
  endfunction


% 1-input NOT gate truth table
% 0 : 1
% 1 : 0
%% signal probability calculator for a 1-input NOT gate
%% input1sp: signal probability of first input signal
%%        s: output signal probability
function s=spNOT(input1sp)
  printf("NOT Gate for input probabilities (%f) :\n",input1sp)
  s = 1 - input1sp

endfunction





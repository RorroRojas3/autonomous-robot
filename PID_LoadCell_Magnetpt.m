function pt=PID_LoadCell_Magnetpt
pt = [];

  
pt(1).blockname = '5V';
pt(1).paramname = 'Value';
pt(1).class     = 'scalar';
pt(1).nrows     = 1;
pt(1).ncols     = 1;
pt(1).subsource = 'SS_DOUBLE';
pt(1).ndims     = '2';
pt(1).size      = '[]';
pt(1).isStruct  = false;
pt(1).symbol     = 'PID_LoadCell_Magnet_P.uV_Value';
pt(1).baseaddr   = '&PID_LoadCell_Magnet_P.uV_Value';
pt(1).dtname     = 'real_T';

pt(getlenPT) = pt(1);


  
pt(2).blockname = 'Degree';
pt(2).paramname = 'Value';
pt(2).class     = 'scalar';
pt(2).nrows     = 1;
pt(2).ncols     = 1;
pt(2).subsource = 'SS_DOUBLE';
pt(2).ndims     = '2';
pt(2).size      = '[]';
pt(2).isStruct  = false;
pt(2).symbol     = 'PID_LoadCell_Magnet_P.Degree_Value';
pt(2).baseaddr   = '&PID_LoadCell_Magnet_P.Degree_Value';
pt(2).dtname     = 'real_T';



  
pt(3).blockname = 'DegreeErrorThresh';
pt(3).paramname = 'Value';
pt(3).class     = 'scalar';
pt(3).nrows     = 1;
pt(3).ncols     = 1;
pt(3).subsource = 'SS_DOUBLE';
pt(3).ndims     = '2';
pt(3).size      = '[]';
pt(3).isStruct  = false;
pt(3).symbol     = 'PID_LoadCell_Magnet_P.DegreeErrorThresh_Value';
pt(3).baseaddr   = '&PID_LoadCell_Magnet_P.DegreeErrorThresh_Value';
pt(3).dtname     = 'real_T';



  
pt(4).blockname = 'RateErrorThresh';
pt(4).paramname = 'Value';
pt(4).class     = 'scalar';
pt(4).nrows     = 1;
pt(4).ncols     = 1;
pt(4).subsource = 'SS_DOUBLE';
pt(4).ndims     = '2';
pt(4).size      = '[]';
pt(4).isStruct  = false;
pt(4).symbol     = 'PID_LoadCell_Magnet_P.RateErrorThresh_Value';
pt(4).baseaddr   = '&PID_LoadCell_Magnet_P.RateErrorThresh_Value';
pt(4).dtname     = 'real_T';



  
pt(5).blockname = 'magnetDrop';
pt(5).paramname = 'Value';
pt(5).class     = 'scalar';
pt(5).nrows     = 1;
pt(5).ncols     = 1;
pt(5).subsource = 'SS_DOUBLE';
pt(5).ndims     = '2';
pt(5).size      = '[]';
pt(5).isStruct  = false;
pt(5).symbol     = 'PID_LoadCell_Magnet_P.magnetDrop_Value';
pt(5).baseaddr   = '&PID_LoadCell_Magnet_P.magnetDrop_Value';
pt(5).dtname     = 'real_T';



  
pt(6).blockname = 'magnetOn';
pt(6).paramname = 'Value';
pt(6).class     = 'scalar';
pt(6).nrows     = 1;
pt(6).ncols     = 1;
pt(6).subsource = 'SS_DOUBLE';
pt(6).ndims     = '2';
pt(6).size      = '[]';
pt(6).isStruct  = false;
pt(6).symbol     = 'PID_LoadCell_Magnet_P.magnetOn_Value';
pt(6).baseaddr   = '&PID_LoadCell_Magnet_P.magnetOn_Value';
pt(6).dtname     = 'real_T';



  
pt(7).blockname = 'Gain';
pt(7).paramname = 'Gain';
pt(7).class     = 'scalar';
pt(7).nrows     = 1;
pt(7).ncols     = 1;
pt(7).subsource = 'SS_DOUBLE';
pt(7).ndims     = '2';
pt(7).size      = '[]';
pt(7).isStruct  = false;
pt(7).symbol     = 'PID_LoadCell_Magnet_P.Gain_Gain';
pt(7).baseaddr   = '&PID_LoadCell_Magnet_P.Gain_Gain';
pt(7).dtname     = 'real_T';



  
pt(8).blockname = 'Kd';
pt(8).paramname = 'Gain';
pt(8).class     = 'scalar';
pt(8).nrows     = 1;
pt(8).ncols     = 1;
pt(8).subsource = 'SS_DOUBLE';
pt(8).ndims     = '2';
pt(8).size      = '[]';
pt(8).isStruct  = false;
pt(8).symbol     = 'PID_LoadCell_Magnet_P.Kd_Gain';
pt(8).baseaddr   = '&PID_LoadCell_Magnet_P.Kd_Gain';
pt(8).dtname     = 'real_T';



  
pt(9).blockname = 'Ki';
pt(9).paramname = 'Gain';
pt(9).class     = 'scalar';
pt(9).nrows     = 1;
pt(9).ncols     = 1;
pt(9).subsource = 'SS_DOUBLE';
pt(9).ndims     = '2';
pt(9).size      = '[]';
pt(9).isStruct  = false;
pt(9).symbol     = 'PID_LoadCell_Magnet_P.Ki_Gain';
pt(9).baseaddr   = '&PID_LoadCell_Magnet_P.Ki_Gain';
pt(9).dtname     = 'real_T';



  
pt(10).blockname = 'Kp';
pt(10).paramname = 'Gain';
pt(10).class     = 'scalar';
pt(10).nrows     = 1;
pt(10).ncols     = 1;
pt(10).subsource = 'SS_DOUBLE';
pt(10).ndims     = '2';
pt(10).size      = '[]';
pt(10).isStruct  = false;
pt(10).symbol     = 'PID_LoadCell_Magnet_P.Kp_Gain';
pt(10).baseaddr   = '&PID_LoadCell_Magnet_P.Kp_Gain';
pt(10).dtname     = 'real_T';



  
pt(11).blockname = 'gain';
pt(11).paramname = 'Gain';
pt(11).class     = 'scalar';
pt(11).nrows     = 1;
pt(11).ncols     = 1;
pt(11).subsource = 'SS_DOUBLE';
pt(11).ndims     = '2';
pt(11).size      = '[]';
pt(11).isStruct  = false;
pt(11).symbol     = 'PID_LoadCell_Magnet_P.gain_Gain';
pt(11).baseaddr   = '&PID_LoadCell_Magnet_P.gain_Gain';
pt(11).dtname     = 'real_T';



  
pt(12).blockname = 'IntegratorPID';
pt(12).paramname = 'InitialCondition';
pt(12).class     = 'scalar';
pt(12).nrows     = 1;
pt(12).ncols     = 1;
pt(12).subsource = 'SS_DOUBLE';
pt(12).ndims     = '2';
pt(12).size      = '[]';
pt(12).isStruct  = false;
pt(12).symbol     = 'PID_LoadCell_Magnet_P.IntegratorPID_IC';
pt(12).baseaddr   = '&PID_LoadCell_Magnet_P.IntegratorPID_IC';
pt(12).dtname     = 'real_T';



  
pt(13).blockname = 'Saturation';
pt(13).paramname = 'UpperLimit';
pt(13).class     = 'scalar';
pt(13).nrows     = 1;
pt(13).ncols     = 1;
pt(13).subsource = 'SS_DOUBLE';
pt(13).ndims     = '2';
pt(13).size      = '[]';
pt(13).isStruct  = false;
pt(13).symbol     = 'PID_LoadCell_Magnet_P.Saturation_UpperSat';
pt(13).baseaddr   = '&PID_LoadCell_Magnet_P.Saturation_UpperSat';
pt(13).dtname     = 'real_T';



  
pt(14).blockname = 'Saturation';
pt(14).paramname = 'LowerLimit';
pt(14).class     = 'scalar';
pt(14).nrows     = 1;
pt(14).ncols     = 1;
pt(14).subsource = 'SS_DOUBLE';
pt(14).ndims     = '2';
pt(14).size      = '[]';
pt(14).isStruct  = false;
pt(14).symbol     = 'PID_LoadCell_Magnet_P.Saturation_LowerSat';
pt(14).baseaddr   = '&PID_LoadCell_Magnet_P.Saturation_LowerSat';
pt(14).dtname     = 'real_T';



  
pt(15).blockname = 'Channel 0 -Control signal to  motor through amplifier ';
pt(15).paramname = 'P1';
pt(15).class     = 'scalar';
pt(15).nrows     = 1;
pt(15).ncols     = 1;
pt(15).subsource = 'SS_DOUBLE';
pt(15).ndims     = '2';
pt(15).size      = '[]';
pt(15).isStruct  = false;
pt(15).symbol     = 'PID_LoadCell_Magnet_P.Channel0Controlsignaltomotort_m';
pt(15).baseaddr   = '&PID_LoadCell_Magnet_P.Channel0Controlsignaltomotort_m';
pt(15).dtname     = 'real_T';



  
pt(16).blockname = 'Channel 0 -Control signal to  motor through amplifier ';
pt(16).paramname = 'P2';
pt(16).class     = 'vector';
pt(16).nrows     = 1;
pt(16).ncols     = 2;
pt(16).subsource = 'SS_DOUBLE';
pt(16).ndims     = '2';
pt(16).size      = '[]';
pt(16).isStruct  = false;
pt(16).symbol     = 'PID_LoadCell_Magnet_P.Channel0Controlsignaltomotort_k';
pt(16).baseaddr   = '&PID_LoadCell_Magnet_P.Channel0Controlsignaltomotort_k[0]';
pt(16).dtname     = 'real_T';



  
pt(17).blockname = 'Channel 0 -Control signal to  motor through amplifier ';
pt(17).paramname = 'P3';
pt(17).class     = 'vector';
pt(17).nrows     = 1;
pt(17).ncols     = 2;
pt(17).subsource = 'SS_DOUBLE';
pt(17).ndims     = '2';
pt(17).size      = '[]';
pt(17).isStruct  = false;
pt(17).symbol     = 'PID_LoadCell_Magnet_P.Channel0Controlsignaltomotort_c';
pt(17).baseaddr   = '&PID_LoadCell_Magnet_P.Channel0Controlsignaltomotort_c[0]';
pt(17).dtname     = 'real_T';



  
pt(18).blockname = 'Channel 0 -Control signal to  motor through amplifier ';
pt(18).paramname = 'P4';
pt(18).class     = 'scalar';
pt(18).nrows     = 1;
pt(18).ncols     = 1;
pt(18).subsource = 'SS_DOUBLE';
pt(18).ndims     = '2';
pt(18).size      = '[]';
pt(18).isStruct  = false;
pt(18).symbol     = 'PID_LoadCell_Magnet_P.Channel0Controlsignaltomotort_d';
pt(18).baseaddr   = '&PID_LoadCell_Magnet_P.Channel0Controlsignaltomotort_d';
pt(18).dtname     = 'real_T';



  
pt(19).blockname = 'Channel 0 -Control signal to  motor through amplifier ';
pt(19).paramname = 'P5';
pt(19).class     = 'vector';
pt(19).nrows     = 1;
pt(19).ncols     = 2;
pt(19).subsource = 'SS_DOUBLE';
pt(19).ndims     = '2';
pt(19).size      = '[]';
pt(19).isStruct  = false;
pt(19).symbol     = 'PID_LoadCell_Magnet_P.Channel0Controlsignaltomotort_n';
pt(19).baseaddr   = '&PID_LoadCell_Magnet_P.Channel0Controlsignaltomotort_n[0]';
pt(19).dtname     = 'real_T';



  
pt(20).blockname = 'Channel 0 -Control signal to  motor through amplifier ';
pt(20).paramname = 'P6';
pt(20).class     = 'vector';
pt(20).nrows     = 1;
pt(20).ncols     = 2;
pt(20).subsource = 'SS_DOUBLE';
pt(20).ndims     = '2';
pt(20).size      = '[]';
pt(20).isStruct  = false;
pt(20).symbol     = 'PID_LoadCell_Magnet_P.Channel0Controlsignaltomotort_g';
pt(20).baseaddr   = '&PID_LoadCell_Magnet_P.Channel0Controlsignaltomotort_g[0]';
pt(20).dtname     = 'real_T';



  
pt(21).blockname = 'Channel 0 -Control signal to  motor through amplifier ';
pt(21).paramname = 'P7';
pt(21).class     = 'scalar';
pt(21).nrows     = 1;
pt(21).ncols     = 1;
pt(21).subsource = 'SS_DOUBLE';
pt(21).ndims     = '2';
pt(21).size      = '[]';
pt(21).isStruct  = false;
pt(21).symbol     = 'PID_LoadCell_Magnet_P.Channel0Controlsignaltomotort_f';
pt(21).baseaddr   = '&PID_LoadCell_Magnet_P.Channel0Controlsignaltomotort_f';
pt(21).dtname     = 'real_T';



  
pt(22).blockname = 'Channel 0 -Control signal to  motor through amplifier ';
pt(22).paramname = 'P8';
pt(22).class     = 'scalar';
pt(22).nrows     = 1;
pt(22).ncols     = 1;
pt(22).subsource = 'SS_DOUBLE';
pt(22).ndims     = '2';
pt(22).size      = '[]';
pt(22).isStruct  = false;
pt(22).symbol     = 'PID_LoadCell_Magnet_P.Channel0Controlsignaltomotor_gv';
pt(22).baseaddr   = '&PID_LoadCell_Magnet_P.Channel0Controlsignaltomotor_gv';
pt(22).dtname     = 'real_T';



  
pt(23).blockname = 'Channel 0 -Control signal to  motor through amplifier ';
pt(23).paramname = 'P9';
pt(23).class     = 'scalar';
pt(23).nrows     = 1;
pt(23).ncols     = 1;
pt(23).subsource = 'SS_DOUBLE';
pt(23).ndims     = '2';
pt(23).size      = '[]';
pt(23).isStruct  = false;
pt(23).symbol     = 'PID_LoadCell_Magnet_P.Channel0Controlsignaltomotor_gp';
pt(23).baseaddr   = '&PID_LoadCell_Magnet_P.Channel0Controlsignaltomotor_gp';
pt(23).dtname     = 'real_T';



  
pt(24).blockname = 'Load Cell';
pt(24).paramname = 'P1';
pt(24).class     = 'scalar';
pt(24).nrows     = 1;
pt(24).ncols     = 1;
pt(24).subsource = 'SS_DOUBLE';
pt(24).ndims     = '2';
pt(24).size      = '[]';
pt(24).isStruct  = false;
pt(24).symbol     = 'PID_LoadCell_Magnet_P.LoadCell_P1';
pt(24).baseaddr   = '&PID_LoadCell_Magnet_P.LoadCell_P1';
pt(24).dtname     = 'real_T';



  
pt(25).blockname = 'Load Cell';
pt(25).paramname = 'P2';
pt(25).class     = 'scalar';
pt(25).nrows     = 1;
pt(25).ncols     = 1;
pt(25).subsource = 'SS_DOUBLE';
pt(25).ndims     = '2';
pt(25).size      = '[]';
pt(25).isStruct  = false;
pt(25).symbol     = 'PID_LoadCell_Magnet_P.LoadCell_P2';
pt(25).baseaddr   = '&PID_LoadCell_Magnet_P.LoadCell_P2';
pt(25).dtname     = 'real_T';



  
pt(26).blockname = 'Load Cell';
pt(26).paramname = 'P3';
pt(26).class     = 'scalar';
pt(26).nrows     = 1;
pt(26).ncols     = 1;
pt(26).subsource = 'SS_DOUBLE';
pt(26).ndims     = '2';
pt(26).size      = '[]';
pt(26).isStruct  = false;
pt(26).symbol     = 'PID_LoadCell_Magnet_P.LoadCell_P3';
pt(26).baseaddr   = '&PID_LoadCell_Magnet_P.LoadCell_P3';
pt(26).dtname     = 'real_T';



  
pt(27).blockname = 'Load Cell';
pt(27).paramname = 'P5';
pt(27).class     = 'scalar';
pt(27).nrows     = 1;
pt(27).ncols     = 1;
pt(27).subsource = 'SS_DOUBLE';
pt(27).ndims     = '2';
pt(27).size      = '[]';
pt(27).isStruct  = false;
pt(27).symbol     = 'PID_LoadCell_Magnet_P.LoadCell_P5';
pt(27).baseaddr   = '&PID_LoadCell_Magnet_P.LoadCell_P5';
pt(27).dtname     = 'real_T';



  
pt(28).blockname = 'Load Cell';
pt(28).paramname = 'P6';
pt(28).class     = 'scalar';
pt(28).nrows     = 1;
pt(28).ncols     = 1;
pt(28).subsource = 'SS_DOUBLE';
pt(28).ndims     = '2';
pt(28).size      = '[]';
pt(28).isStruct  = false;
pt(28).symbol     = 'PID_LoadCell_Magnet_P.LoadCell_P6';
pt(28).baseaddr   = '&PID_LoadCell_Magnet_P.LoadCell_P6';
pt(28).dtname     = 'real_T';



  
pt(29).blockname = 'Load Cell';
pt(29).paramname = 'P7';
pt(29).class     = 'scalar';
pt(29).nrows     = 1;
pt(29).ncols     = 1;
pt(29).subsource = 'SS_DOUBLE';
pt(29).ndims     = '2';
pt(29).size      = '[]';
pt(29).isStruct  = false;
pt(29).symbol     = 'PID_LoadCell_Magnet_P.LoadCell_P7';
pt(29).baseaddr   = '&PID_LoadCell_Magnet_P.LoadCell_P7';
pt(29).dtname     = 'real_T';



  
pt(30).blockname = 'Sine Wave';
pt(30).paramname = 'Amplitude';
pt(30).class     = 'scalar';
pt(30).nrows     = 1;
pt(30).ncols     = 1;
pt(30).subsource = 'SS_DOUBLE';
pt(30).ndims     = '2';
pt(30).size      = '[]';
pt(30).isStruct  = false;
pt(30).symbol     = 'PID_LoadCell_Magnet_P.SineWave_Amp';
pt(30).baseaddr   = '&PID_LoadCell_Magnet_P.SineWave_Amp';
pt(30).dtname     = 'real_T';



  
pt(31).blockname = 'Sine Wave';
pt(31).paramname = 'Bias';
pt(31).class     = 'scalar';
pt(31).nrows     = 1;
pt(31).ncols     = 1;
pt(31).subsource = 'SS_DOUBLE';
pt(31).ndims     = '2';
pt(31).size      = '[]';
pt(31).isStruct  = false;
pt(31).symbol     = 'PID_LoadCell_Magnet_P.SineWave_Bias';
pt(31).baseaddr   = '&PID_LoadCell_Magnet_P.SineWave_Bias';
pt(31).dtname     = 'real_T';



  
pt(32).blockname = 'Sine Wave';
pt(32).paramname = 'Frequency';
pt(32).class     = 'scalar';
pt(32).nrows     = 1;
pt(32).ncols     = 1;
pt(32).subsource = 'SS_DOUBLE';
pt(32).ndims     = '2';
pt(32).size      = '[]';
pt(32).isStruct  = false;
pt(32).symbol     = 'PID_LoadCell_Magnet_P.SineWave_Freq';
pt(32).baseaddr   = '&PID_LoadCell_Magnet_P.SineWave_Freq';
pt(32).dtname     = 'real_T';



  
pt(33).blockname = 'Sine Wave';
pt(33).paramname = 'Phase';
pt(33).class     = 'scalar';
pt(33).nrows     = 1;
pt(33).ncols     = 1;
pt(33).subsource = 'SS_DOUBLE';
pt(33).ndims     = '2';
pt(33).size      = '[]';
pt(33).isStruct  = false;
pt(33).symbol     = 'PID_LoadCell_Magnet_P.SineWave_Phase';
pt(33).baseaddr   = '&PID_LoadCell_Magnet_P.SineWave_Phase';
pt(33).dtname     = 'real_T';



  
pt(34).blockname = 'Switch1';
pt(34).paramname = 'Threshold';
pt(34).class     = 'scalar';
pt(34).nrows     = 1;
pt(34).ncols     = 1;
pt(34).subsource = 'SS_DOUBLE';
pt(34).ndims     = '2';
pt(34).size      = '[]';
pt(34).isStruct  = false;
pt(34).symbol     = 'PID_LoadCell_Magnet_P.Switch1_Threshold';
pt(34).baseaddr   = '&PID_LoadCell_Magnet_P.Switch1_Threshold';
pt(34).dtname     = 'real_T';



  
pt(35).blockname = 'Switch2';
pt(35).paramname = 'Threshold';
pt(35).class     = 'scalar';
pt(35).nrows     = 1;
pt(35).ncols     = 1;
pt(35).subsource = 'SS_DOUBLE';
pt(35).ndims     = '2';
pt(35).size      = '[]';
pt(35).isStruct  = false;
pt(35).symbol     = 'PID_LoadCell_Magnet_P.Switch2_Threshold';
pt(35).baseaddr   = '&PID_LoadCell_Magnet_P.Switch2_Threshold';
pt(35).dtname     = 'real_T';



  
pt(36).blockname = 'Real motor/angular_position =  [relative_count//COUNTS_PER_REV] *360 degrees';
pt(36).paramname = 'Gain';
pt(36).class     = 'scalar';
pt(36).nrows     = 1;
pt(36).ncols     = 1;
pt(36).subsource = 'SS_DOUBLE';
pt(36).ndims     = '2';
pt(36).size      = '[]';
pt(36).isStruct  = false;
pt(36).symbol     = 'PID_LoadCell_Magnet_P.angular_positionrelative_countC';
pt(36).baseaddr   = '&PID_LoadCell_Magnet_P.angular_positionrelative_countC';
pt(36).dtname     = 'real_T';



  
pt(37).blockname = 'Real motor/Channel 0 of  Encoder Inputs ';
pt(37).paramname = 'P1';
pt(37).class     = 'scalar';
pt(37).nrows     = 1;
pt(37).ncols     = 1;
pt(37).subsource = 'SS_DOUBLE';
pt(37).ndims     = '2';
pt(37).size      = '[]';
pt(37).isStruct  = false;
pt(37).symbol     = 'PID_LoadCell_Magnet_P.Channel0ofEncoderInputs_P1';
pt(37).baseaddr   = '&PID_LoadCell_Magnet_P.Channel0ofEncoderInputs_P1';
pt(37).dtname     = 'real_T';



  
pt(38).blockname = 'Real motor/Channel 0 of  Encoder Inputs ';
pt(38).paramname = 'P2';
pt(38).class     = 'scalar';
pt(38).nrows     = 1;
pt(38).ncols     = 1;
pt(38).subsource = 'SS_DOUBLE';
pt(38).ndims     = '2';
pt(38).size      = '[]';
pt(38).isStruct  = false;
pt(38).symbol     = 'PID_LoadCell_Magnet_P.Channel0ofEncoderInputs_P2';
pt(38).baseaddr   = '&PID_LoadCell_Magnet_P.Channel0ofEncoderInputs_P2';
pt(38).dtname     = 'real_T';



  
pt(39).blockname = 'Real motor/Channel 0 of  Encoder Inputs ';
pt(39).paramname = 'P3';
pt(39).class     = 'scalar';
pt(39).nrows     = 1;
pt(39).ncols     = 1;
pt(39).subsource = 'SS_DOUBLE';
pt(39).ndims     = '2';
pt(39).size      = '[]';
pt(39).isStruct  = false;
pt(39).symbol     = 'PID_LoadCell_Magnet_P.Channel0ofEncoderInputs_P3';
pt(39).baseaddr   = '&PID_LoadCell_Magnet_P.Channel0ofEncoderInputs_P3';
pt(39).dtname     = 'real_T';



  
pt(40).blockname = 'Real motor/Channel 0 of  Encoder Inputs ';
pt(40).paramname = 'P4';
pt(40).class     = 'scalar';
pt(40).nrows     = 1;
pt(40).ncols     = 1;
pt(40).subsource = 'SS_DOUBLE';
pt(40).ndims     = '2';
pt(40).size      = '[]';
pt(40).isStruct  = false;
pt(40).symbol     = 'PID_LoadCell_Magnet_P.Channel0ofEncoderInputs_P4';
pt(40).baseaddr   = '&PID_LoadCell_Magnet_P.Channel0ofEncoderInputs_P4';
pt(40).dtname     = 'real_T';



  
pt(41).blockname = 'Real motor/Channel 0 of  Encoder Inputs ';
pt(41).paramname = 'P5';
pt(41).class     = 'scalar';
pt(41).nrows     = 1;
pt(41).ncols     = 1;
pt(41).subsource = 'SS_DOUBLE';
pt(41).ndims     = '2';
pt(41).size      = '[]';
pt(41).isStruct  = false;
pt(41).symbol     = 'PID_LoadCell_Magnet_P.Channel0ofEncoderInputs_P5';
pt(41).baseaddr   = '&PID_LoadCell_Magnet_P.Channel0ofEncoderInputs_P5';
pt(41).dtname     = 'real_T';



  
pt(42).blockname = 'Real motor/Channel 0 of  Encoder Inputs ';
pt(42).paramname = 'P6';
pt(42).class     = 'scalar';
pt(42).nrows     = 1;
pt(42).ncols     = 1;
pt(42).subsource = 'SS_DOUBLE';
pt(42).ndims     = '2';
pt(42).size      = '[]';
pt(42).isStruct  = false;
pt(42).symbol     = 'PID_LoadCell_Magnet_P.Channel0ofEncoderInputs_P6';
pt(42).baseaddr   = '&PID_LoadCell_Magnet_P.Channel0ofEncoderInputs_P6';
pt(42).dtname     = 'real_T';



  
pt(43).blockname = 'Real motor/Channel 0 of  Encoder Inputs ';
pt(43).paramname = 'P7';
pt(43).class     = 'scalar';
pt(43).nrows     = 1;
pt(43).ncols     = 1;
pt(43).subsource = 'SS_DOUBLE';
pt(43).ndims     = '2';
pt(43).size      = '[]';
pt(43).isStruct  = false;
pt(43).symbol     = 'PID_LoadCell_Magnet_P.Channel0ofEncoderInputs_P7';
pt(43).baseaddr   = '&PID_LoadCell_Magnet_P.Channel0ofEncoderInputs_P7';
pt(43).dtname     = 'real_T';



  
pt(44).blockname = 'Real motor/Channel 0 of  Encoder Inputs ';
pt(44).paramname = 'P8';
pt(44).class     = 'scalar';
pt(44).nrows     = 1;
pt(44).ncols     = 1;
pt(44).subsource = 'SS_DOUBLE';
pt(44).ndims     = '2';
pt(44).size      = '[]';
pt(44).isStruct  = false;
pt(44).symbol     = 'PID_LoadCell_Magnet_P.Channel0ofEncoderInputs_P8';
pt(44).baseaddr   = '&PID_LoadCell_Magnet_P.Channel0ofEncoderInputs_P8';
pt(44).dtname     = 'real_T';



  
pt(45).blockname = 'Real motor/Channel 0 of  Encoder Inputs ';
pt(45).paramname = 'P9';
pt(45).class     = 'scalar';
pt(45).nrows     = 1;
pt(45).ncols     = 1;
pt(45).subsource = 'SS_DOUBLE';
pt(45).ndims     = '2';
pt(45).size      = '[]';
pt(45).isStruct  = false;
pt(45).symbol     = 'PID_LoadCell_Magnet_P.Channel0ofEncoderInputs_P9';
pt(45).baseaddr   = '&PID_LoadCell_Magnet_P.Channel0ofEncoderInputs_P9';
pt(45).dtname     = 'real_T';



  
pt(46).blockname = 'Real motor/Channel 0 of  Encoder Inputs ';
pt(46).paramname = 'P10';
pt(46).class     = 'scalar';
pt(46).nrows     = 1;
pt(46).ncols     = 1;
pt(46).subsource = 'SS_DOUBLE';
pt(46).ndims     = '2';
pt(46).size      = '[]';
pt(46).isStruct  = false;
pt(46).symbol     = 'PID_LoadCell_Magnet_P.Channel0ofEncoderInputs_P10';
pt(46).baseaddr   = '&PID_LoadCell_Magnet_P.Channel0ofEncoderInputs_P10';
pt(46).dtname     = 'real_T';



  
pt(47).blockname = 'Real motor/Channel 0 of  Encoder Inputs ';
pt(47).paramname = 'P11';
pt(47).class     = 'scalar';
pt(47).nrows     = 1;
pt(47).ncols     = 1;
pt(47).subsource = 'SS_DOUBLE';
pt(47).ndims     = '2';
pt(47).size      = '[]';
pt(47).isStruct  = false;
pt(47).symbol     = 'PID_LoadCell_Magnet_P.Channel0ofEncoderInputs_P11';
pt(47).baseaddr   = '&PID_LoadCell_Magnet_P.Channel0ofEncoderInputs_P11';
pt(47).dtname     = 'real_T';



  
pt(48).blockname = 'Real motor/Channel 0 of  Encoder Inputs ';
pt(48).paramname = 'P12';
pt(48).class     = 'scalar';
pt(48).nrows     = 1;
pt(48).ncols     = 1;
pt(48).subsource = 'SS_DOUBLE';
pt(48).ndims     = '2';
pt(48).size      = '[]';
pt(48).isStruct  = false;
pt(48).symbol     = 'PID_LoadCell_Magnet_P.Channel0ofEncoderInputs_P12';
pt(48).baseaddr   = '&PID_LoadCell_Magnet_P.Channel0ofEncoderInputs_P12';
pt(48).dtname     = 'real_T';


function len = getlenPT
len = 48;


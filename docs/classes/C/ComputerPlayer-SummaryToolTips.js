﻿NDSummary.OnToolTipsLoaded("CClass:ComputerPlayer",{87:"<div class=\"NDToolTip TClass LC\"><div class=\"NDClassPrototype\" id=\"NDClassPrototype87\"><div class=\"CPEntry TClass Current\"><div class=\"CPName\">ComputerPlayer</div></div></div><div class=\"TTSummary\">Class of a player handled by computer. Main purpose of class is to create player and process player interaction with board.&nbsp; Also, the class will handle minmax algorithm.</div></div>",89:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype89\" class=\"NDPrototype WideForm\"><div class=\"PSection PParameterSection CStyle\"><table><tr><td class=\"PBeforeParameters\">Point&amp; SimulateMove(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PModifierQualifier first\"><span class=\"SHKeyword\">const</span> std::</td><td class=\"PType\">vector&lt;Point&gt;&amp;&nbsp;</td><td class=\"PName last\">availableMoves</td></tr></table></td><td class=\"PAfterParameters\">)</td></tr></table></div></div><div class=\"TTSummary\">Simulates move of real player. Currently, it chooses point randomly. In the future it will choose it based on the MINMAX algorithm.</div></div>",90:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype90\" class=\"NDPrototype WideForm\"><div class=\"PSection PParameterSection CStyle\"><table><tr><td class=\"PBeforeParameters\">std::array&lt;Point, <span class=\"SHNumber\">2</span>&gt; ChooseMove(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PModifierQualifier first\"><span class=\"SHKeyword\">const</span> std::</td><td class=\"PType\">vector&lt;Point&gt;&amp;&nbsp;</td><td class=\"PName last\">availableOuterBoardMoves,</td></tr><tr><td class=\"PModifierQualifier first\">std::</td><td class=\"PType\">vector&lt;std::vector&lt;Point&gt;&gt;&nbsp;</td><td class=\"PName last\">availableInnerBoardMoves,</td></tr><tr><td class=\"first\"></td><td class=\"PType\"><span class=\"SHKeyword\">int</span>&nbsp;</td><td class=\"PName last\">boardSize</td></tr></table></td><td class=\"PAfterParameters\">) <span class=\"SHKeyword\">override</span></td></tr></table></div></div><div class=\"TTSummary\">Simulates move of real player. Currently, it chooses point randomly. In the future it will choose it based on the MINMAX algorithm.</div></div>",91:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype91\" class=\"NDPrototype WideForm\"><div class=\"PSection PParameterSection CStyle\"><table><tr><td class=\"PBeforeParameters\">ComputerPlayer(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PType first\"><span class=\"SHKeyword\">char</span>&nbsp;</td><td class=\"PName last\">symbol</td></tr></table></td><td class=\"PAfterParameters\">)</td></tr></table></div></div><div class=\"TTSummary\">Constructor which takes symbol which computer player will use during game.</div></div>"});
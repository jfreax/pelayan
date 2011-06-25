

var nick       = "user";
var color      = 0;

var colors;

/** set nickname of the user and send a string to the server */
function setNick() {
  psNick = document.getElementById("txtNick").value;
   sendNewLine(applyColor(nick, colors[color]) + " hat sich in " 
	      + applyColor(psNick, colors[color]) 
	      + " umbenannt.<br>");
  nick = psNick;
  document.getElementById("txtMsg").focus();
}


/** started by loading the page */
function initialize() {
  colors = new Array();
  colors[0]  = "000000";
  colors[1]  = "003300";
  colors[2]  = "006600";
  colors[3]  = "009900";
  colors[4]  = "00CC00";
  colors[5]  = "00FF00";
  colors[6]  = "000033";
  colors[7]  = "003333";
  colors[8]  = "006633";
  colors[9]  = "009933";
  colors[10]  = "00CC33";
  colors[11]  = "00FF33";
  colors[12]  = "000066";
  colors[13]  = "003366";
  colors[14]  = "006666";
  colors[15]  = "009966";
  colors[16]  = "00CC66";
  colors[17]  = "00FF66";
  colors[18]  = "000099";
  colors[19]  = "003399";
  colors[20]  = "006699";
  colors[21]  = "009999";
  colors[22]  = "00CC99";
  colors[23]  = "00FF99";
  colors[24]  = "0000CC";
  colors[25]  = "0033CC";
  colors[26]  = "0066CC";
  colors[27]  = "0099CC";
  colors[28]  = "00CCCC";
  colors[29]  = "00FFCC";
  colors[30]  = "0000FF";
  colors[31]  = "0033FF";
  colors[32]  = "0066FF";
  colors[33]  = "0099FF";
  colors[34]  = "00CCFF";
  colors[35]  = "00FFFF";
  colors[36]  = "000000";
  colors[37]  = "330000";
  colors[38]  = "660000";
  colors[39]  = "990000";
  colors[40]  = "CC0000";
  colors[41]  = "FF0000";
  colors[42]  = "000033";
  colors[43]  = "330033";
  colors[44]  = "660033";
  colors[45]  = "990033";
  colors[46]  = "CC0033";
  colors[47]  = "FF0033";
  colors[48]  = "000066";
  colors[49]  = "330066";
  colors[50]  = "660066";
  colors[51]  = "990066";
  colors[52]  = "CC0066";
  colors[53]  = "FF0066";
  colors[54]  = "000099";
  colors[55]  = "330099";
  colors[56]  = "660099";
  colors[57]  = "990099";
  colors[58]  = "CC0099";
  colors[59]  = "FF0099";
  colors[60]  = "0000CC";
  colors[61]  = "3300CC";
  colors[62]  = "6600CC";
  colors[63]  = "9900CC";
  colors[64]  = "CC00CC";
  colors[65]  = "FF00CC";
  colors[66]  = "0000FF";
  colors[67]  = "3300FF";
  colors[68]  = "6600FF";
  colors[69]  = "9900FF";
  colors[70]  = "CC00FF";
  colors[71]  = "FF00FF";
  colors[72]  = "000000";
  colors[73]  = "330000";
  colors[74]  = "660000";
  colors[75]  = "990000";
  colors[76]  = "CC0000";
  colors[77]  = "FF0000";
  colors[78]  = "003300";
  colors[79]  = "333300";
  colors[80]  = "663300";
  colors[81]  = "993300";
  colors[82]  = "CC3300";
  colors[83]  = "FF3300";
  colors[84]  = "006600";
  colors[85]  = "336600";
  colors[86]  = "666600";
  colors[87]  = "996600";
  colors[88]  = "CC6600";
  colors[89]  = "FF6600";
  colors[90]  = "009900";
  colors[91]  = "339900";
  colors[92]  = "669900";
  colors[93]  = "999900";
  colors[94]  = "CC9900";
  colors[95]  = "FF9900";
  colors[96]  = "00CC00";
  colors[97]  = "33CC00";
  colors[98]  = "66CC00";
  colors[99]  = "99CC00";
  colors[100]  = "CCCC00";
  colors[101]  = "FFCC00";
  colors[102]  = "00FF00";
  colors[103]  = "33FF00";
  colors[104]  = "66FF00";
  colors[105]  = "99FF00";
  colors[106]  = "CCFF00";
  colors[107]  = "FFFF00";

  document.getElementById("colbox").bgColor = "#" + colors[color];
	
  document.getElementById("txtMsg").onkeypress  = txtMsg_KeyPress;
  document.getElementById("txtNick").onkeypress = txtNick_KeyPress;

  document.getElementById("txtNick").value = nick;

  document.getElementById("txtMsg").focus();
  buildColorTable();


  
  block(); /* create async. connection and wait for data from the server */
  
  sendNewLine(nick + " hat den chat betreten.<br>"); /* send a info text to the server */
}


function setColor(newColor) {
  color = newColor;
  document.getElementById("colbox").bgColor = "#" + colors[color];
  document.getElementById("txtMsg").focus();
}

function buildColorTable() {
  var code = '<center><table><tr>';

  for (i = 0; i < colors.length; i++) {
    code += '<td id="colbox[' + i + ']" style="cursor: pointer;" height="14" width="20" bgcolor="#' 
      + colors[i] + '" onclick="setColor(' + i + ')"></td>'
      if ((i + 1) % 6 == 0) {
	code += '</tr><tr>';
      }
  }

  code += '</tr></table></center>';

  document.getElementById("ColorTable").innerHTML = code;
}


/** write messsage to chat frame. */
function setChat(msg) {
  
  var mp = document.getElementById("MessagePanel");
  
  mp.innerHTML = msg;
  mp.scrollTop = mp.scrollHeight - mp.clientHeight;

}


function txtNick_KeyPress(keyEvent) {
  if (isReturn(keyEvent)) {
    document.getElementById("btnNick").click();
  }
}
function txtMsg_KeyPress(keyEvent) {
  if (isReturn(keyEvent)) {
    document.getElementById("btnSubmit").click();
  }
}


/**
 *  IO
 */
function sendChatMessage() {
  var psMsg = document.getElementById("txtMsg").value;

  sendNewLine(applyColor(nick + ' (' + getTime() + '): ', colors[color]) + psMsg + '<br>');
  var msg = document.getElementById("txtMsg");
  msg.value = "";
  msg.focus();
}

function onReceived(msg) {
  setChat(msg);
}

/**
 *  Helpers
 */
function isReturn(keyEvent) {
  var code = keyEvent.keyCode;

  if (code == 13) {
    return (true);
  }
  return (false);
}

function applyColor(data, col) {
  return ('<font color="#' + col + '">' + data + '</font>');
}

function getTime() {
  var res = "";

  var now = new Date();


  if (now.getHours() < 10) res += "0";
  res += now.getHours();
  res += ":";
  if (now.getMinutes() < 10) res += "0";
  res += now.getMinutes();
  res += ":";
  if (now.getSeconds() < 10) res += "0";
  res += now.getSeconds();

  return (res);
}


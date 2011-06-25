
var connection; // The blocked XMLHttpRequest.

/** Send a new Line of text to the server.
 *  We use a seperate connection for transmitting data to the server. 
 */
function sendNewLine(text) {
  var con = new XMLHttpRequest();
  if (!con) { 
    alert("Could not create background connection.");
    return false;
  }
  
  var baseUrl = location.protocol + "//" + location.hostname + ":" + location.port;
  con.open('post', decodeURI(baseUrl + '/broadcast.service'), true);

  con.send(text);
  return true;
}



function block() {


  connection = new XMLHttpRequest();
  
  if (!connection) {
    alert("cannot create connection object");
    return 1;
  }

  var baseUrl = location.protocol + "//" + location.hostname + ":" + location.port;
  
  /* connect to the server, most important, the 3rd parameter must be TRUE to
   * make this an asynchronous connection 
   */
  connection.open('post', decodeURI(baseUrl + '/broadcast.service'), true);
  
  /** call handleResponse when something interesting happens on the connection.
   *  This will normally be the arrival of new data, or that the connection is 
   *  finished. 
   */
  connection.onreadystatechange = handleResponse;

  connection.send(""); /* Send a POST request of size 0 */
  
  /* The reception of data is done asynchronously (in the background),
   * however, the handleResponse function will be called when finished.
   */
}


/**
 * Callback function
 */
function handleResponse() {
  // readyState
  // 0 UNINITIALIZED open() has not been called yet.
  // 1 LOADING send() has not been called yet.
  // 2 LOADED send() has been called, headers and status are available.
  // 3 INTERACTIVE Downloading, responseText holds the partial data.
  // 4 COMPLETED Finished with all operations.
  
  
  if (connection.readyState == 4) {
    if (connection.responseText.length > 0) {
      onReceived(connection.responseText);
      block();
    } 
    
  }
}


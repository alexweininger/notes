Use case template

Name: login and verification
Description: verifying card and the pin
Actors: card reader, user, verification server
Frequency: 1
Priority: ultimate priority of security
Precondition: they have inserted their card into the card reader
Primary flow: enter in pin code, check against server data, make sure both connections are encrypted
Alternative Flow: unable to verify the user, they are a fraud!
Non-functional: security, pin code wall
Open issues: none, our code is perfect

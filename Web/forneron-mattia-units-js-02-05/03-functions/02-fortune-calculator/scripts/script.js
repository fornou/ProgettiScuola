//Start Functions
function tellFortune(jobTitle, geoLocation, partnerName, numberOfChildren) {
    console.log("You will be a "+ jobTitle +" in "+ geoLocation +", and married to "+ partnerName +" with "+ numberOfChildren +" kids.")
}
//End Function


tellFortune("Nurse", "Rome", "Jessica", 1);
tellFortune("Developer", "Berlin", "Monica", 3);
tellFortune("Taxi Driver", "Moscow", "Sara", 2);

/*
    The result in console-browser:
    You will be a Nurse in Rome, and married to Jessica with 1 kids.
    You will be a Developer in Berlin, and married to Monica with 3 kids.
    You will be a Taxi Driver in Moscow, and married to Sara with 2 kids.
*/
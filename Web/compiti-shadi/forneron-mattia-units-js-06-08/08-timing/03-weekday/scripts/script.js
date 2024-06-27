function getWeekDay(date, language) {
    let weekdays;
    if(language=='en'){
        weekdays = ['SU', 'MO', 'TU', 'WE', 'TH', 'FR', 'SA'];
    }else if(language=='it'){
        weekdays = ['DO', 'LU', 'MA', 'ME', 'GI', 'VE', 'SA'];
    }
    let dayIndex = date.getDay();
    return weekdays[dayIndex];
}

const date = new Date(); 
console.log(getWeekDay(date, 'en'));
console.log(getWeekDay(date, 'it')); 

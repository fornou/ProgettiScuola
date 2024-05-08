$(document).ready(function(){
    $("#myInput").on("keyup", function() {
        var value = $(this).val().toLowerCase();
        $("#myTable tr").each(function() {
            $(this).toggle(
                $(this).text().toLowerCase().indexOf(value) > -1 || value.length === 0
            );
        });
    });
});

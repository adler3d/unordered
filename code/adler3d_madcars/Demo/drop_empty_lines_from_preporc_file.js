return POST.data.split("\n").
filter(e=>e.length>0).
filter(e=>e.trim().length).
filter(e=>e.split("#line ").length==1).
filter(e=>e.split("#pragma once").length==1).
join("\n")
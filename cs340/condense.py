slfile = open("spelllist.txt", "r")
sdfile = open("spelldescs.txt","r")
spfile = open("spell_list_final.txt","w")

spell_list = slfile.read()
spell_list = spell_list.split('\n')
#for line in slfile:
#    line = line.rstrip('\r\n')
#    spell_list.append(line)

max_size = 0

bigg = sdfile.read()
bigg = bigg.split('\n')
i = 0
j = 0
for item in bigg:
    spell = []
    #find each spell name
    if item in spell_list:
        in_spell = False
        #find the rest of each spell desc.
        for subitem in bigg:
            if item == subitem and subitem in spell_list:
                in_spell = True
                i = 0
                #flip flag for being in spell
            elif item != subitem and subitem in spell_list and in_spell == True:
                #if the subitem is a different spell name and we've already
                #found the spell name we're looking for, we must have finished
                #the spell description, so break out of this loop
                break
            if in_spell == True and i < 7:
                spell.append(subitem)
                i = i + 1
            elif in_spell == True and i >= 7:
                spell[6] = spell[6] + ' ' + subitem
#        print spell
        spell_list[j] = spell
        j = j + 1
#print spell_list
for spell in spell_list:
    for field in spell:
        if len(field) > max_size:
            max_size = len(field)
        spfile.write(field)
        spfile.write('|')
    spfile.write('\n')

print max_size

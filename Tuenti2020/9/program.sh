    chr() {
        printf \\$(printf '%03o' $1)
    }
    
    function hex() {
        printf '%02X\n' $1
    }

    function ascii_to_char() {
        printf "\x$(printf %x $1)"
    }

    function dec() {
        echo "obase=10; ibase=16; $1" | bc
    }
    
    function encrypt() {
        key=$1
        msg=$2
        crpt_msg=""
        for ((i=0; i<${#msg}; i++)); do
            c=${msg:$i:1}
            asc_chr=$(echo -ne "$c" | od -An -tuC)
            key_pos=$((${#key} - 1 - ${i}))
            key_char=${key:$key_pos:1}
            crpt_chr=$(( $asc_chr ^ ${key_char} ))
            hx_crpt_chr=$(hex $crpt_chr)
            crpt_msg=${crpt_msg}${hx_crpt_chr}
        done
        echo $crpt_msg
    }

    function decrypt() {
        key=$2
        msg=$1
        dcript_msg=""
        for ((i=0; i <${#key}; i++)); do
            c2=${key:$i:1}
            a=$(( 2*i ))
            c1=${msg:$a:2}
            c1=$(dec $c1)
            y=$(( $c1 ^ ${c2} ))
            y=$(ascii_to_char $y)
            dcript_msg+=$y
        done
        echo $dcript_msg     
    }

    function get_key() {
        msg=$1
        enc=$2
        key=""
        for ((i=0; i <${#msg}; i++)); do
            c1=${msg:$i:1}
            a=$(( 2*i ))
            c2=${enc:$a:2}
            c1=$(echo -ne "$c1" | od -An -tuC)
            c2=$(dec $c2)
            y=$(( $c1 ^ ${c2} ))
            key=${key}${y}
        done
        echo $key
    }

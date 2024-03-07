document.getElementById('download-btn').addEventListener('click', (e) => {
    e.preventDefault();
    let xhr = new XMLHttpRequest();
    xhr.open('GET', '/download-brochure', true);
    xhr.responseType = 'blob';

    xhr.onload = function() {
        if (xhr.status === 200) {
            let blob = new Blob([xhr.response], { type: 'application/octet-stream; charset=UTF-8' });
            let url = window.URL.createObjectURL(blob);
            let link = document.createElement('a');
            link.href = url;
            console.log(link)
            link.setAttribute('download', '파일명.pdf');
            document.body.appendChild(link);
            link.click();
            document.body.removeChild(link);
            window.URL.revokeObjectURL(url);
        }
    };

    xhr.send();
});
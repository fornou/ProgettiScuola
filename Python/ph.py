import pornhub
keywords = ["gatta", "topa"]
client = pornhub.PornHub(keywords)

for video in client.getVideos(10, page=2, full_data=True):
  print(video)
  print(video["upload_date"])